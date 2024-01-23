#include "dbusframework.h"


void DbusFramework::registerService(const QString &name, const QString &dbusService, const QString &dbusPath, const QString &dbusInterface)
{
    router_.insert_or_assign(name, std::make_tuple(dbusService, dbusPath, dbusInterface));
}

QVariant DbusFramework::callMethod(const QString &serviceName, const QString &method, const QStringList &args)
{
    try {
        return ApplicationService::updateApplicationArgs(router_.at(serviceName),
                                                         method,
                                                         args);
    } catch (const std::out_of_range &e) {
        return QVariant("Service doesn't exist");
    } catch (const std::exception &e) {
        return QVariant::fromValue(e.what());
    }
}
