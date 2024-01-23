#include "applicationservice.h"

#include <QtGui/QGuiApplication>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusConnectionInterface>

const QString dbusServiceStr = QStringLiteral(DBUS_SERVICE);
const QString dbusPathStr = QStringLiteral(DBUS_PATH);
const QString dbusIfaceStr = QStringLiteral(DBUS_INTERFACE);

ApplicationService::ApplicationService(QObject *parent) : QDBusAbstractAdaptor(parent)
{
    QDBusConnection dbus = QDBusConnection::sessionBus();
    dbus.registerObject(dbusPathStr, parent, QDBusConnection::ExportAllSlots);
    if (!isRegistered(dbusServiceStr)) {
        bool success = dbus.registerService(dbusServiceStr);
        if (!success)
            qApp->quit();
    }
}

ApplicationService::~ApplicationService()
{
    QDBusConnection dbus = QDBusConnection::sessionBus();
    dbus.unregisterObject(dbusPathStr);
    dbus.unregisterService(dbusServiceStr);
}

bool ApplicationService::isRegistered(const QString &dbusService)
{
    return QDBusConnection::sessionBus().interface()->isServiceRegistered(dbusService);
}

QString ApplicationService::getService() noexcept
{
    return dbusServiceStr;
}

QString ApplicationService::getPath() noexcept
{
    return dbusPathStr;
}

QString ApplicationService::getInterface() noexcept
{
    return dbusIfaceStr;
}

QVariant ApplicationService::updateApplicationArgs(const std::tuple<QString, QString, QString> &applicationDbusData,
                                                   const QString &method,
                                                   const QStringList &arguments)
{
    auto [dbusService, dbusPath, dbusIface] = applicationDbusData;
    QDBusMessage message = QDBusMessage::createMethodCall(dbusService, dbusPath, dbusIface, method);
    for(const auto &string : arguments){
        message << string;
    }
    QDBusMessage reply = QDBusConnection::sessionBus().call(message);
    return reply.arguments().empty() ? QVariant() : reply.arguments().takeFirst();
}
