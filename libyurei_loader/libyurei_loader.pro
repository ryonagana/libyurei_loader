TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../main_test.c \
    ../obj_loader.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../obj_loader.h

