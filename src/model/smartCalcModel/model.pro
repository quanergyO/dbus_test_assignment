QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

QT += dbus

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../application/smartCalcApplication/applicationcontroller.cpp \
    ../../application/smartCalcApplication/controllerAdaptor.cpp \
    ../../include/dbus_framework/applicationService/applicationservice.cpp \
    Model.cc \
    Token.cc \
    Tokenizer.cc \
    main.cpp \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../../application/smartCalcApplication/applicationcontroller.h \
    ../../application/smartCalcApplication/controllerAdaptor.h \
    ../../include/dbus_framework/applicationService/applicationservice.h \
    headers/Error.h \
    headers/Model.h \
    headers/Token.h \
    headers/Tokenizer.h


DEFINES += \
    DBUS_SERVICE=\\\"ru.model.SmartCalc\\\" \
    DBUS_PATH=\\\"/ru/model/SmartCalc\\\" \
    DBUS_INTERFACE=\\\"ru.model.SmartCalc\\\" \
    APP_ID_FILE_PATH=\\\"$${APP_ID_PATH}/$${APP_ID_FILE}\\\" \
