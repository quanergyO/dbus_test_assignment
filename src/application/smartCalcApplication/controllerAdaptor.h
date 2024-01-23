/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp ru.model.SmartCalc.xml -i applicationcontroller.h -a controllerAdaptor
 *
 * qdbusxml2cpp is Copyright (C) 2023 The Qt Company Ltd and other contributors.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef CONTROLLERADAPTOR_H
#define CONTROLLERADAPTOR_H

#include <QtCore/QObject>
#include <QDBusAbstractAdaptor>
#include "applicationcontroller.h"
#include <QtCore/qcontainerfwd.h>

/*
 * Adaptor class for interface ru.model.SmartCalc
 */
class SmartCalcAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ru.model.SmartCalc")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"ru.model.SmartCalc\">\n"
"    <method name=\"calculateExpression\">\n"
"      <arg direction=\"out\" type=\"d\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"expression\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    SmartCalcAdaptor(QObject *parent);
    virtual ~SmartCalcAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    double calculateExpression(const QString &expression);
Q_SIGNALS: // SIGNALS
};

#endif