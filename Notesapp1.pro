QT       += core gui widgets

CONFIG += c++17 debug

SOURCES += \
    createnote.cpp \
    dashboard.cpp \
    doodleview.cpp \
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
    doodleview.h \
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

# Set output directories
win32 {
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/debug
    } else {
        DESTDIR = $$PWD/release
    }
} else {
    DESTDIR = $$PWD/release
}

QMAKE_CXXFLAGS_DEBUG += -g3 -O0

# Deployment paths (optional)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
