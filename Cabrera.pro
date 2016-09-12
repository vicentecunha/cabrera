#-------------------------------------------------
#
# Project created by QtCreator 2016-06-27T09:16:18
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cabrera
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp \
    vo2000interface.cpp \
    patient.cpp \
    newpatient.cpp \
    warningdialog.cpp \
    editpatient.cpp \
    newanamnesis.cpp \
    anamnesis.cpp \
    editanamnesis.cpp

HEADERS  += mainwindow.h \
    about.h \
    vo2000interface.h \
    patient.h \
    newpatient.h \
    warningdialog.h \
    editpatient.h \
    constants.h \
    newanamnesis.h \
    anamnesis.h \
    editanamnesis.h

FORMS    += \
    mainwindow.ui \
    about.ui \
    vo2000interface.ui \
    newpatient.ui \
    warningdialog.ui \
    newanamnesis.ui

OTHER_FILES +=

RESOURCES += \
    img.qrc

CONFIG += \
    c++11
