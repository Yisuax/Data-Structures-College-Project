TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    menu.cpp \
    aldeanos.cpp \
    civilizacion.cpp \
    guerreros.cpp \
    recursos.cpp

HEADERS += \
    menu.h \
    aldeanos.h \
    civilizacion.h \
    arreglo.h \
    lista.h \
    listadoble.h \
    guerreros.h \
    colaprioridad.h \
    recursos.h \
    mapeo.h
