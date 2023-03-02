#include "viewer.h"

Viewer::Viewer(QWidget *parent) : QOpenGLWidget(parent) {
  connect(&tmr, SIGNAL(timeout()), this, SLOT(update()));
  tmr.start(100);
}
void Viewer::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glClearColor(0, 0, 0, 1);
}
void Viewer::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glClearDepth(1.0);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Viewer::paintGL() {
  glClearColor(background_color.redF(), background_color.greenF(),
               background_color.blueF(), 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //
  glMatrixMode(GL_PROJECTION);  // Делаем центральную проекцию
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();  // Наша матрица будет единичной
  if (perspective == -1) {
    glOrtho(-1.5, 1.5, -1.5, 1.5, -2, 1000);
  } else {
    glFrustum(-1, 1, -1, 1, 1, 3);
    glTranslatef(0, 0, -2);
  }
  if (x > -181) glRotatef(x, 1, 0, 0);
  if (y > -181) glRotatef(y, 0, 1, 0);
  if (z > -181) glRotatef(z, 0, 0, 1);
  glRotatef(xRot, 1, 0, 0);  // вращение матрицы по Х
  glRotatef(yRot, 0, 1, 0);  // вращение матрицы по Y
  if (data != NULL) {
    draw();
  }
}

void Viewer::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

void Viewer::mouseMoveEvent(QMouseEvent *mo) {
  xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
  yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
  update();
}

void Viewer::draw() {
  if (edge_type < 0) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(3, 0x00FF);
  }
  glLineWidth(edge_size);
  glColor3f(color_edge.redF(), color_edge.greenF(), color_edge.blueF());
  int count = 0;

  while (count < data->polygon->count_sequences) {
    Queue *tmp = NULL;
    int shift = 0;
    glBegin(GL_LINE_LOOP);
    while ((shift = pop(&data->polygon->sequence->points)) != -1) {
      data->vertex->coordinate += shift - 1;
      double one = (data->vertex->coordinate->x + x_shift) * scale;
      double two = (data->vertex->coordinate->y + y_shift) * scale;
      double three = (data->vertex->coordinate->z + z_shift) * scale;
      data->vertex->coordinate -= shift - 1;
      tmp = push(tmp, shift);
      glVertex3d(one, two, three);
    }
    glEnd();
    data->polygon->sequence->points = tmp;
    data->polygon->sequence++;
    count++;
  }

  if (edge_type < 0) glDisable(GL_LINE_STIPPLE);
  data->polygon->sequence -= data->polygon->count_sequences;
  if (vertex_type != -1) {
    count = 0;
    while (count < data->polygon->count_sequences) {
      Queue *tmp = NULL;
      int shift = 0;
      glEnable(vertex_type);
      glPointSize(vertex_size);
      glColor3f(color_vertex.redF(), color_vertex.greenF(),
                color_vertex.blueF());
      glBegin(GL_POINTS);
      while ((shift = pop(&data->polygon->sequence->points)) != -1) {
        data->vertex->coordinate += shift - 1;
        double one = (data->vertex->coordinate->x + x_shift) * scale;
        double two = (data->vertex->coordinate->y + y_shift) * scale;
        double three = (data->vertex->coordinate->z + z_shift) * scale;
        data->vertex->coordinate -= shift - 1;
        tmp = push(tmp, shift);
        glVertex3d(one, two, three);
      }
      glEnd();
      data->polygon->sequence->points = tmp;
      data->polygon->sequence++;
      count++;
    }
    glDisable(vertex_type);
    data->polygon->sequence -= data->polygon->count_sequences;
  }
}

Viewer::~Viewer() {}
