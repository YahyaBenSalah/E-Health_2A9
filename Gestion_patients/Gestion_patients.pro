QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    main.cpp \
    mainwindow.cpp \
    medecin.cpp \
    medecin2.cpp \
    mededcin1.cpp \
    menu.cpp \
    patient.cpp \
    secondwindow.cpp

HEADERS += \
    connexion.h \
    mainwindow.h \
    medecin.h \
    medecin2.h \
    mededcin1.h \
    menu.h \
    patient.h \
    secondwindow.h

FORMS += \
    mainwindow.ui \
    medecin2.ui \
    mededcin1.ui \
    menu.ui \
    secondwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
