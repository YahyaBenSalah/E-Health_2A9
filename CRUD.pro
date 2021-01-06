QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = CRUD

TEMPLATE = app

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    main.cpp \
    mainwindow.cpp \
    maladie.cpp \
    medicament.cpp

HEADERS += \
    connexion.h \
    mainwindow.h \
    maladie.h \
    medicament.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
