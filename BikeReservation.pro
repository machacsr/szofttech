TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mainapp.cpp \
    bike.cpp \
    reservation.cpp \
    comment.cpp \
    owner.cpp \
    operator.cpp \
    admin.cpp \
    repairman.cpp \
    accessory.cpp

HEADERS += \
    mainapp.h \
    bike.h \
    reservation.h \
    comment.h \
    owner.h \
    operator.h \
    admin.h \
    repairman.h \
    accessory.h
