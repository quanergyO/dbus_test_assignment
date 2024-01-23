#ifndef DBUSFRAMEWORK_H
#define DBUSFRAMEWORK_H

#include <QObject>
#include <QString>
#include <QList>
#include <utility>
#include <unordered_map>
#include <tuple>

#include "applicationService/applicationservice.h"



class DbusFramework : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ru.framework.DbusFramework")
public:
    DbusFramework() = default;
public slots:
    void registerService(const QString &name, const QString &dbusService, const QString &dbusPath, const QString &dbusInterface);
    QVariant callMethod(const QString &serviceName, const QString &method, const QStringList &args);

private:
    std::unordered_map<QString, std::tuple<QString, QString, QString>> router_;
};

#endif // DBUSFRAMEWORK_H
