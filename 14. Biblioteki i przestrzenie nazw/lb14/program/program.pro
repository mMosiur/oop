TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += ../biblioteka

LIBS += -L../build-biblioteka-Desktop-Debug -lbiblioteka
