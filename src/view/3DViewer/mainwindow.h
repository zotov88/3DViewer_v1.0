#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QSettings>
#include <cstring>

#include "ima/qgifimage_p.h"

extern "C" {
#include "../../backend/parcer.h"
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT
  QImage mp[50];
  int check;
  QTimer *timer_gif;

 public:
  QSettings *settings;
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  QGifImage gif;

 public slots:

  void loadSettings();
  void saveSettings();

 private slots:

  void on_X_valueChanged(double arg1);
  void on_Y_valueChanged(double arg1);
  void on_Z_valueChanged(double arg1);
  void on_Color_back_clicked();
  void on_file_clicked();
  void on_Z_shift_valueChanged(double arg1);
  void on_X_shift_valueChanged(double arg1);
  void on_Y_shift_valueChanged(double arg1);
  void on_Scale_valueChanged(double arg1);
  void on_perspective_released();
  void on_horizontalSlider_valueChanged(int value);
  void on_Color_edge_clicked();
  void on_Color_Vertex_clicked();
  void on_horizontalSlider_2_valueChanged(int value);
  void on_square_toggled(bool checked);
  void on_circle_toggled(bool checked);
  void on_None_toggled(bool checked);
  void on_dotten_released();
  void on_exit_bt_clicked();
  void reset_parameters();
  void setVandP();
  char *string_to_ptr(QString string);
  void on_bt_reset_clicked();
  void on_br_forget_clicked();
  void on_pushB_SaveGIF_clicked();
  void timer_grab();
  void on_pushB_saveFPEG_clicked();
  void on_pushB_saveBMP_clicked();

 private:
  QString fileName;
  Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_H
