#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  loadSettings();
}

MainWindow::~MainWindow() {
  saveSettings();
  if (ui->widget->data != NULL) {
    destroy_main_struct(ui->widget->data);
  }
  delete ui;
}

void MainWindow::saveSettings() {
  QSettings settings("settings_Viewer", "Conf");
  settings.setValue("X_translation", ui->X_shift->value());
  settings.setValue("Y_translation", ui->Y_shift->value());
  settings.setValue("Z_translation", ui->Z_shift->value());
  settings.setValue("X_rotation", ui->X->value());
  settings.setValue("Y_rotation", ui->Y->value());
  settings.setValue("Z_rotation", ui->Z->value());
  settings.setValue("Scale", ui->Scale->value());
  settings.setValue("Edge_size", ui->horizontalSlider->value());
  settings.setValue("Vertex_size", ui->horizontalSlider_2->value());
  settings.setValue("Dotten", ui->dotten->isChecked());
  settings.setValue("Perspective", ui->perspective->isChecked());
  settings.setValue("text", ui->path_file->text());
}

void MainWindow::loadSettings() {
  QSettings settings("settings_Viewer", "Conf");
  ui->path_file->setText(settings.value("text", "").toString());
  fileName = ui->path_file->text();
  ui->filename->setText(fileName.split('/').last());
  if (fileName.length() != 0) {
    ui->widget->data = main_function(string_to_ptr(fileName));
    setVandP();
  }
  ui->X_shift->setValue(settings.value("X_translation", 0).toInt());
  ui->Y_shift->setValue(settings.value("Y_translation", 0).toInt());
  ui->Z_shift->setValue(settings.value("Z_translation", 0).toInt());
  ui->X->setValue(settings.value("X_rotation", 0).toInt());
  ui->Y->setValue(settings.value("Y_rotation", 0).toInt());
  ui->Z->setValue(settings.value("Z_rotation", 0).toInt());
  ui->Scale->setValue(settings.value("Scale", 0).toDouble());
  ui->horizontalSlider->setValue(settings.value("Edge_size", 0).toInt());
  ui->horizontalSlider_2->setValue(settings.value("Vertex_size", 0).toInt());
  ui->dotten->setChecked(settings.value("Dotten").toBool());
  ui->widget->edge_type = ui->dotten->isChecked() ? -1 : 1;
  ui->perspective->setChecked(settings.value("Perspective").toBool());
  ui->widget->perspective = ui->perspective->isChecked() ? 1 : -1;
}

void MainWindow::setVandP() {
  if (ui->widget->data != NULL) {
    int p = ui->widget->data->polygon->count_sequences;
    int v = ui->widget->data->vertex->count_coordinates;
    ui->lb_pol->setText("Pol: " + QString::number(p));
    ui->lb_ver->setText("Ver: " + QString::number(v));
  }
}

char *MainWindow::string_to_ptr(QString string) {
  QByteArray ba = string.toLocal8Bit();
  return ba.data();
}

void MainWindow::on_X_valueChanged(double val) { this->ui->widget->x = val; }

void MainWindow::on_Y_valueChanged(double val) { this->ui->widget->y = val; }

void MainWindow::on_Z_valueChanged(double val) { this->ui->widget->z = val; }

void MainWindow::on_Color_back_clicked() {
  ui->widget->background_color =
      QColorDialog::getColor(Qt::white, this, tr("Select Color"));
}

void MainWindow::on_file_clicked() {
  QString fileName =
      QFileDialog::getOpenFileName(this, "Open file", "~/", "*.obj");
  if (fileName.length() != 0) {
    ui->filename->setText(fileName.split('/').last());
    ui->path_file->setText(fileName);
    char *path = string_to_ptr(fileName);
    if (ui->widget->data != NULL) {
      destroy_main_struct(ui->widget->data);
    }
    reset_parameters();
    ui->widget->data = main_function(path);
    setVandP();
  }
}

void MainWindow::reset_parameters() {
  ui->X_shift->setValue(0);
  ui->Y_shift->setValue(0);
  ui->Z_shift->setValue(0);
  ui->Scale->setValue(0);
  ui->X->setValue(0);
  ui->Y->setValue(0);
  ui->Z->setValue(0);
  ui->perspective->setChecked(false);
  ui->widget->perspective = -1;
  ui->dotten->setChecked(false);
  ui->widget->edge_type = 1;
  ui->horizontalSlider->setValue(0);
  ui->horizontalSlider_2->setValue(0);
}

void MainWindow::on_X_shift_valueChanged(double val) {
  ui->widget->x_shift = val * 0.01;
}

void MainWindow::on_Y_shift_valueChanged(double val) {
  ui->widget->y_shift = val * 0.01;
}

void MainWindow::on_Z_shift_valueChanged(double val) {
  ui->widget->z_shift = val * 0.01;
}

void MainWindow::on_Scale_valueChanged(double val) {
  if (val != 0)
    ui->widget->scale = 1 + val * 0.1;
  else
    ui->widget->scale = 1;
}

void MainWindow::on_perspective_released() { ui->widget->perspective *= -1; }

void MainWindow::on_dotten_released() { ui->widget->edge_type *= -1; }

void MainWindow::on_horizontalSlider_valueChanged(int value) {
  ui->widget->edge_size = value;
}

void MainWindow::on_Color_edge_clicked() {
  ui->widget->color_edge =
      QColorDialog::getColor(Qt::white, this, tr("Select Color"));
}

void MainWindow::on_Color_Vertex_clicked() {
  ui->widget->color_vertex =
      QColorDialog::getColor(Qt::white, this, tr("Select Color"));
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value) {
  ui->widget->vertex_size = value;
}

void MainWindow::on_square_toggled(bool checked) {
  if (checked) ui->widget->vertex_type = GL_POINTS;
}

void MainWindow::on_circle_toggled(bool checked) {
  if (checked) ui->widget->vertex_type = GL_POINT_SMOOTH;
}

void MainWindow::on_None_toggled(bool checked) {
  if (checked) ui->widget->vertex_type = -1;
}

void MainWindow::on_exit_bt_clicked() {
  if (ui->widget->data != NULL) {
    destroy_main_struct(ui->widget->data);
  }
  saveSettings();
  exit(0);
}

void MainWindow::on_bt_reset_clicked() { reset_parameters(); }

void MainWindow::on_br_forget_clicked() {
  reset_parameters();
  ui->path_file->setText("");
  on_exit_bt_clicked();
}

void MainWindow::on_pushB_SaveGIF_clicked() {
  check = 0;
  timer_gif = new QTimer();
  connect(timer_gif, SIGNAL(timeout()), this, SLOT(timer_grab()));
  timer_gif->start(100);
  ui->pushB_SaveGIF->setEnabled(0);
}

void MainWindow::timer_grab() {
  if (check > 49) {
    timer_gif->stop();
    disconnect(timer_gif);
    check = 0;
    for (int i = 0; i < 50; gif.addFrame(mp[i++], 200)) {
    }
    QString str = QFileDialog::getSaveFileName(0, "Сохранить файл как",
                                               "name.gif", "*.gif");
    gif.save(str);
    ui->pushB_SaveGIF->setText("GIF");
    ui->pushB_SaveGIF->setEnabled(1);
  } else {
    mp[check] = ui->widget->grab().toImage();
    check += 1;
    ui->pushB_SaveGIF->setText(QString::number(check / 10));
  }
}

void MainWindow::on_pushB_saveFPEG_clicked() {
  QString str = QFileDialog::getSaveFileName(this, "Save as...", "name.jpeg",
                                             "JPEG (*.jpg *.jpeg)");
  if (!str.isEmpty()) {
    ui->widget->grab().save(str);
  }
}

void MainWindow::on_pushB_saveBMP_clicked() {
  QString str = QFileDialog::getSaveFileName(this, "Save as...", "name.bmp",
                                             "BMP (*.bmp)");
  if (!str.isEmpty()) {
    ui->widget->grab().save(str);
  }
}
