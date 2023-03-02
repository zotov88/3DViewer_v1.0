/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <viewer.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QDoubleSpinBox *X;
    QDoubleSpinBox *Y;
    QDoubleSpinBox *Z;
    QLabel *path_file;
    QCheckBox *perspective;
    QPushButton *Color_back;
    QLabel *filename;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lb_ver;
    QLabel *lb_pol;
    QPushButton *file;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_6;
    QDoubleSpinBox *X_shift;
    QDoubleSpinBox *Y_shift;
    QDoubleSpinBox *Z_shift;
    QLabel *label_3;
    QDoubleSpinBox *Scale;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *dotten;
    QLabel *label_4;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Color_edge;
    QPushButton *Color_Vertex;
    QLabel *label_5;
    QSlider *horizontalSlider_2;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *None;
    QRadioButton *square;
    QRadioButton *circle;
    QPushButton *pushB_SaveGIF;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushB_saveFPEG;
    QPushButton *pushB_saveBMP;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *bt_reset;
    QPushButton *exit_bt;
    QPushButton *br_forget;
    Viewer *widget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1074, 795);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        X = new QDoubleSpinBox(centralwidget);
        X->setObjectName(QString::fromUtf8("X"));
        X->setMinimum(-180.000000000000000);
        X->setMaximum(180.000000000000000);

        horizontalLayout_5->addWidget(X);

        Y = new QDoubleSpinBox(centralwidget);
        Y->setObjectName(QString::fromUtf8("Y"));
        Y->setMinimum(-180.000000000000000);
        Y->setMaximum(180.000000000000000);

        horizontalLayout_5->addWidget(Y);

        Z = new QDoubleSpinBox(centralwidget);
        Z->setObjectName(QString::fromUtf8("Z"));
        Z->setMinimum(-180.000000000000000);
        Z->setMaximum(180.000000000000000);

        horizontalLayout_5->addWidget(Z);


        verticalLayout->addLayout(horizontalLayout_5);

        path_file = new QLabel(centralwidget);
        path_file->setObjectName(QString::fromUtf8("path_file"));
        path_file->setMaximumSize(QSize(0, 0));
        path_file->setScaledContents(false);

        verticalLayout->addWidget(path_file);

        perspective = new QCheckBox(centralwidget);
        perspective->setObjectName(QString::fromUtf8("perspective"));
        perspective->setChecked(false);

        verticalLayout->addWidget(perspective);

        Color_back = new QPushButton(centralwidget);
        Color_back->setObjectName(QString::fromUtf8("Color_back"));

        verticalLayout->addWidget(Color_back);

        filename = new QLabel(centralwidget);
        filename->setObjectName(QString::fromUtf8("filename"));
        filename->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(filename);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lb_ver = new QLabel(centralwidget);
        lb_ver->setObjectName(QString::fromUtf8("lb_ver"));

        horizontalLayout_8->addWidget(lb_ver);

        lb_pol = new QLabel(centralwidget);
        lb_pol->setObjectName(QString::fromUtf8("lb_pol"));

        horizontalLayout_8->addWidget(lb_pol);


        verticalLayout->addLayout(horizontalLayout_8);

        file = new QPushButton(centralwidget);
        file->setObjectName(QString::fromUtf8("file"));

        verticalLayout->addWidget(file);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        X_shift = new QDoubleSpinBox(centralwidget);
        X_shift->setObjectName(QString::fromUtf8("X_shift"));
        X_shift->setMinimum(-100.000000000000000);
        X_shift->setMaximum(100.000000000000000);

        horizontalLayout_6->addWidget(X_shift);

        Y_shift = new QDoubleSpinBox(centralwidget);
        Y_shift->setObjectName(QString::fromUtf8("Y_shift"));
        Y_shift->setMinimum(-100.000000000000000);
        Y_shift->setMaximum(100.000000000000000);

        horizontalLayout_6->addWidget(Y_shift);

        Z_shift = new QDoubleSpinBox(centralwidget);
        Z_shift->setObjectName(QString::fromUtf8("Z_shift"));
        Z_shift->setMinimum(-100.000000000000000);
        Z_shift->setMaximum(100.000000000000000);

        horizontalLayout_6->addWidget(Z_shift);


        verticalLayout->addLayout(horizontalLayout_6);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        Scale = new QDoubleSpinBox(centralwidget);
        Scale->setObjectName(QString::fromUtf8("Scale"));
        Scale->setMinimum(-100.000000000000000);
        Scale->setMaximum(100.000000000000000);

        verticalLayout->addWidget(Scale);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        dotten = new QCheckBox(centralwidget);
        dotten->setObjectName(QString::fromUtf8("dotten"));

        horizontalLayout_4->addWidget(dotten);


        verticalLayout->addLayout(horizontalLayout_4);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMaximum(10);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Color_edge = new QPushButton(centralwidget);
        Color_edge->setObjectName(QString::fromUtf8("Color_edge"));

        horizontalLayout_2->addWidget(Color_edge);

        Color_Vertex = new QPushButton(centralwidget);
        Color_Vertex->setObjectName(QString::fromUtf8("Color_Vertex"));

        horizontalLayout_2->addWidget(Color_Vertex);


        verticalLayout->addLayout(horizontalLayout_2);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        sizePolicy.setHeightForWidth(horizontalSlider_2->sizePolicy().hasHeightForWidth());
        horizontalSlider_2->setSizePolicy(sizePolicy);
        horizontalSlider_2->setMaximum(10);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_2);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        None = new QRadioButton(centralwidget);
        None->setObjectName(QString::fromUtf8("None"));
        None->setChecked(false);

        horizontalLayout_3->addWidget(None);

        square = new QRadioButton(centralwidget);
        square->setObjectName(QString::fromUtf8("square"));
        square->setChecked(true);

        horizontalLayout_3->addWidget(square);

        circle = new QRadioButton(centralwidget);
        circle->setObjectName(QString::fromUtf8("circle"));

        horizontalLayout_3->addWidget(circle);


        verticalLayout->addLayout(horizontalLayout_3);

        pushB_SaveGIF = new QPushButton(centralwidget);
        pushB_SaveGIF->setObjectName(QString::fromUtf8("pushB_SaveGIF"));

        verticalLayout->addWidget(pushB_SaveGIF);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushB_saveFPEG = new QPushButton(centralwidget);
        pushB_saveFPEG->setObjectName(QString::fromUtf8("pushB_saveFPEG"));

        horizontalLayout_7->addWidget(pushB_saveFPEG);

        pushB_saveBMP = new QPushButton(centralwidget);
        pushB_saveBMP->setObjectName(QString::fromUtf8("pushB_saveBMP"));

        horizontalLayout_7->addWidget(pushB_saveBMP);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        verticalLayout->addLayout(horizontalLayout_9);

        bt_reset = new QPushButton(centralwidget);
        bt_reset->setObjectName(QString::fromUtf8("bt_reset"));

        verticalLayout->addWidget(bt_reset);

        exit_bt = new QPushButton(centralwidget);
        exit_bt->setObjectName(QString::fromUtf8("exit_bt"));

        verticalLayout->addWidget(exit_bt);

        br_forget = new QPushButton(centralwidget);
        br_forget->setObjectName(QString::fromUtf8("br_forget"));

        verticalLayout->addWidget(br_forget);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        widget = new Viewer(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(exit_bt, &QPushButton::released, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3DViewer", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Rotate (X, Y, Z)", nullptr));
        path_file->setText(QString());
        perspective->setText(QCoreApplication::translate("MainWindow", "Perspective", nullptr));
        Color_back->setText(QCoreApplication::translate("MainWindow", "Color background", nullptr));
        filename->setText(QString());
        lb_ver->setText(QString());
        lb_pol->setText(QString());
        file->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Shifting (X, Y, Z)", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        dotten->setText(QCoreApplication::translate("MainWindow", "dotten line edge", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Edge size", nullptr));
        Color_edge->setText(QCoreApplication::translate("MainWindow", "Color edge", nullptr));
        Color_Vertex->setText(QCoreApplication::translate("MainWindow", "Color vertex", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Vertex size", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Vertex politic", nullptr));
        None->setText(QCoreApplication::translate("MainWindow", "none", nullptr));
        square->setText(QCoreApplication::translate("MainWindow", "square", nullptr));
        circle->setText(QCoreApplication::translate("MainWindow", "circle", nullptr));
        pushB_SaveGIF->setText(QCoreApplication::translate("MainWindow", "Save GIF", nullptr));
        pushB_saveFPEG->setText(QCoreApplication::translate("MainWindow", "Save JPEG", nullptr));
        pushB_saveBMP->setText(QCoreApplication::translate("MainWindow", "Save BMP", nullptr));
        bt_reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        exit_bt->setText(QCoreApplication::translate("MainWindow", "Exit and Save", nullptr));
        br_forget->setText(QCoreApplication::translate("MainWindow", "Exit and Forget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
