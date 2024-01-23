QT -= gui


CONFIG += c++17 console
CONFIG -= app_bundle

QT += dbus

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../../application/creditCalcApplication/creditCalcAdaptor.cpp \
        ../../application/creditCalcApplication/creditcalccontroller.cpp \
        ../../include/dbus_framework/applicationService/applicationservice.cpp \
        main.cpp \
        modelcreditcalc.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../../application/creditCalcApplication/creditCalcAdaptor.h \
    ../../application/creditCalcApplication/creditcalccontroller.h \
    ../../include/dbus_framework/applicationService/applicationservice.h \
    modelcreditcalc.h


DEFINES += \
    DBUS_SERVICE=\\\"ru.credit.CreditCalc\\\" \
    DBUS_PATH=\\\"/ru/credit/CreditCalc\\\" \
    DBUS_INTERFACE=\\\"ru.credit.CreditCalc\\\" \
    APP_ID_FILE_PATH=\\\"$${APP_ID_PATH}/$${APP_ID_FILE}\\\" \
