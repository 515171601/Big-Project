TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    function.cpp \
    ImportDrug.cpp \
    NormalDrug.cpp \
    DrugManage.cpp \
    Drug.cpp \
    BargainDrug.cpp

HEADERS += \
    header.h \
    function.h \
    ImportDrug.h \
    NormalDrug.h \
    DrugManage.h \
    Drug.h \
    BargainDrug.h
