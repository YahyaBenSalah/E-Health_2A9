QT       += core gui sql serialport printsupport multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    bilan.cpp \
    comptes.cpp \
    connection.cpp \
    dossiermedicale.cpp \
    exportexcelobject.cpp \
    fiche.cpp \
    main.cpp \
    mainwindow.cpp \
    maladie.cpp \
    maladie1.cpp \
    medecin.cpp \
    medicament.cpp \
    patient.cpp

HEADERS += \
    arduino.h \
    bilan.h \
    comptes.h \
    connection.h \
    dossiermedicale.h \
    exportexcelobject.h \
    fiche.h \
    mainwindow.h \
    maladie.h \
    maladie1.h \
    medecin.h \
    medicament.h \
    patient.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    244.png \
    Sound.wav \
    SpyBot.qss \
    play.png

RESOURCES +=
