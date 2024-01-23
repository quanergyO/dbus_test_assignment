QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

QT += dbus

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    applicationService/applicationservice.cpp \
    dbusframework.cpp \
    frameworkAdaptor.cpp \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    applicationService/applicationservice.h \
    dbusframework.h \
    frameworkAdaptor.h

DEFINES += \
    DBUS_SERVICE=\\\"ru.framework.DbusFramework\\\" \
    DBUS_PATH=\\\"/ru/framework/DbusFramework\\\" \
    DBUS_INTERFACE=\\\"ru.framework.DbusFramework\\\" \
    APP_ID_FILE_PATH=\\\"$${APP_ID_PATH}/$${APP_ID_FILE}\\\" \
