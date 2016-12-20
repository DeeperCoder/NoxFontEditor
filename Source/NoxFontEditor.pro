#-------------------------------------------------
#
# Project created by QtCreator 2016-10-16T03:36:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NoxFontEditor
TEMPLATE = app


SOURCES +=\
        nfe_mainwindow.cpp \
    noxfontfile.cpp \
    NFE.cpp \
    noxsymbol.cpp

HEADERS  += nfe_mainwindow.h \
    noxfontfile.h \
    noxsymbol.h

FORMS    += nfe_mainwindow.ui

win32:RC_ICONS += nfe.ico
