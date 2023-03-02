#ifndef VIEWER_H
#define VIEWER_H

#include <GL/gl.h>

#include <QBasicTimer>
#include <QKeyEvent>
#include <QMainWindow>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtOpenGL>
#include <QtOpenGLWidgets/QtOpenGLWidgets>
#include <QtWidgets/QWidget>
#include <vector>

extern "C" {
#include "../../backend/parcer.h"
};

QT_BEGIN_NAMESPACE
namespace Ui {
class Viewer;
}
QT_END_NAMESPACE

class Viewer : public QOpenGLWidget {
  Q_OBJECT
 private:
  float xRot, yRot, zRot;
  float x_coordinate, y_coordinate, z_coordinate;
  QPoint mPos;
  QTimer tmr;
  void draw();
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

 public:
  Viewer(QWidget *parent = nullptr);
  MainStruct *data = NULL;
  int perspective = -1;
  int edge_size = 1;
  int vertex_size = 1;
  int vertex_type = 0;
  int edge_type = 1;
  float x, y, z;
  float scale = 1;
  float x_shift = 0, y_shift = 0, z_shift = 0;
  QColor background_color = QColorConstants::DarkCyan;
  QColor color_edge = QColorConstants::White;
  QColor color_vertex = QColorConstants::White;
  const char *fileName;
  ~Viewer();

 private slots:

 private:
  Ui::Viewer *ui;
};
#endif  // VIEWER_H
