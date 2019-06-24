TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += gui

SOURCES += main.cpp \
    parcel.cpp \
    agroparcel.cpp \
    buildingparcel.cpp \
    matrix.cpp

HEADERS += \
    parcel.h \
    agroparcel.h \
    buildingparcel.h \
    matrix.h
