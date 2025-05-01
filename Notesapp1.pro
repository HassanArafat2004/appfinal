QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    createnote.cpp \
    dashboard.cpp \
    main.cpp \
    mainwindow.cpp \
    notelist.cpp \
    reports.cpp \
    signup.cpp \
    user.cpp \
    adminwindow.cpp

HEADERS += \
    createnote.h \
    dashboard.h \
    mainwindow.h \
    notelist.h \
    reports.h \
    signup.h \
    user.h \
    adminwindow.h

FORMS += \
    createnote.ui \
    dashboard.ui \
    mainwindow.ui \
    notelist.ui \
    reports.ui \
    signup.ui \
    adminwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
