TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bike.cpp \
    reservation.cpp \
    operator.cpp \
    repairman.cpp \
    owner.cpp \
    employee.cpp \
    admin.cpp

HEADERS += \
    bike.h \
    reservation.h \
    operator.h \
    repairman.h \
    owner.h \
    employee.h \
    admin.h
