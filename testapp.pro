#-------------------------------------------------
#
# Project created by QtCreator 2016-06-10T11:33:25
#
#-------------------------------------------------

QT       += core gui
#QT       += sql
#QT       += webenginewidgets
#unix: CONFIG	+= link_pkgconfig
#unix: PKGCONFIG += gtk+-3.0

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testapp
TEMPLATE = app

LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
# LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_videoio
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
# LIBS += -lopencv_contrib
# LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_superres
LIBS += -lopencv_imgcodecs
#LIBS += -lR
#LIBS += -lpq
#LIBS += -lopencv_nonfree

SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    tools.cpp \
    testdialog.cpp

HEADERS  += mainwindow.h \
    player.h \
    tools.h \
    testdialog.h

FORMS    += mainwindow.ui \
    testdialog.ui

#INCLUDEPATH += /usr/lib/R/site-library/Rcpp/include
#INCLUDEPATH += /usr/share/R/include

#QMAKE_CXXFLAGS += -Wno-extra # seems not to work, still warnings about RCPP_CTOR_ASSIGN (rcpp)
