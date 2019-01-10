QT += core
QT -= gui

CONFIG += c++11

TARGET = MyShellCommand
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../

SOURCES += main.cpp \
    ../ShellCommand.cpp


HEADERS += \
    ../ShellCommand.h
