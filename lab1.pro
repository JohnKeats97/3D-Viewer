#-------------------------------------------------
#
# Project created by QtCreator 2017-03-17T14:26:14
#
#-------------------------------------------------

QT       += opengl gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += opengl

TARGET = 3D-Viewer
TEMPLATE = app

LIBS += -lglut
SOURCES += main.cpp\
        mainwindow.cpp \
    start_model.cpp \
    special_keys.cpp \
    create_model.cpp \
    change_model.cpp \
    draw_model.cpp \
    model.cpp

HEADERS  += mainwindow.h \
    model.h
