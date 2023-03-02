QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets openglwidgets
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets
greaterThan(QT_MAJOR_VERSION, 6): QT += openglwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../backend/parcer.c \
    ../../backend/transformation.c \
    ima/giflib/dgif_lib.c \
    ima/giflib/egif_lib.c \
    ima/giflib/gif_err.c \
    ima/giflib/gif_font.c \
    ima/giflib/gif_hash.c \
    ima/giflib/gifalloc.c \
    ima/giflib/quantize.c \
    ima/qgifimage.cpp \
    main.cpp \
    mainwindow.cpp \
    viewer.cpp

HEADERS += \
    ../../backend/parcer.h \
    ../../backend/transformation.h \
    ima/giflib/gif_hash.h \
    ima/giflib/gif_lib.h \
    ima/giflib/gif_lib_private.h \
    ima/qgifglobal.h \
    ima/qgifimage.h \
    ima/qgifimage_p.h \
    mainwindow.h \
    viewer.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ima/gifimage.pro

DISTFILES += \
    ima/giflib/AUTHORS \
    ima/giflib/COPYING \
    ima/giflib/README
