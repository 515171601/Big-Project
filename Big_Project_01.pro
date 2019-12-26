TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    drug.cpp \
    normaldrug.cpp \
    importdrug.cpp \
    bargaindrug.cpp

HEADERS += \
    header.h \
    drug.h \
    normaldrug.h \
    importdrug.h \
    bargaindrug.h
