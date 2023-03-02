#include <QApplication>

#include "mainwindow.h"
#include "viewer.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  setlocale(LC_NUMERIC, "C");
  Viewer w;
  MainWindow x;
  x.show();
  return a.exec();
}
