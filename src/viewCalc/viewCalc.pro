QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

QT += dbus

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../include/dbus_framework/applicationService/applicationservice.cpp \
    ../include/dbus_framework/dbusframework.cpp \
    ../include/dbus_framework/frameworkAdaptor.cpp \
    creditwindow.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    ../include/dbus_framework/applicationService/applicationservice.h \
    ../include/dbus_framework/dbusframework.h \
    ../include/dbus_framework/frameworkAdaptor.h \
    creditwindow.h \
    mainwindow.h \

FORMS += \
    creditwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DEFINES += \
    DBUS_SERVICE=\\\"ru.framework.DbusFramework\\\" \
    DBUS_PATH=\\\"/ru/framework/DbusFramework\\\" \
    DBUS_INTERFACE=\\\"ru.framework.DbusFramework\\\" \
    APP_ID_FILE_PATH=\\\"$${APP_ID_PATH}/$${APP_ID_FILE}\\\" \
