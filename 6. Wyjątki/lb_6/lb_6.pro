TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    house.cpp \
    room.cpp \
    oversizeddoorexception.cpp

HEADERS += \
    house.h \
    room.h \
    oversizeddoorexception.h
