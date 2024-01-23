/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp ru.framework.DbusFramework.xml -i dbusframework.h -a frameworkAdaptor
 *
 * qdbusxml2cpp is Copyright (C) 2023 The Qt Company Ltd and other contributors.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef FRAMEWORKADAPTOR_H
#define FRAMEWORKADAPTOR_H

#include <QtCore/QObject>
#include <QDBusAbstractAdaptor>
#include "dbusframework.h"
#include <QtCore/qcontainerfwd.h>

/*
 * Adaptor class for interface ru.framework.DbusFramework
 */
class DbusFrameworkAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ru.framework.DbusFramework")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"ru.framework.DbusFramework\">\n"
"    <method name=\"registerService\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"name\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"dbusService\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"dbusPath\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"dbusInterface\"/>\n"
"    </method>\n"
"    <method name=\"callMethod\">\n"
"      <arg direction=\"out\" type=\"v\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"serviceName\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"method\"/>\n"
"      <arg direction=\"in\" type=\"as\" name=\"args\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    DbusFrameworkAdaptor(QObject *parent);
    virtual ~DbusFrameworkAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    QVariant callMethod(const QString &serviceName, const QString &method, const QStringList &args);
    void registerService(const QString &name, const QString &dbusService, const QString &dbusPath, const QString &dbusInterface);
Q_SIGNALS: // SIGNALS
};

#endif
