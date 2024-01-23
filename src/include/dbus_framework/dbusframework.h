
#ifndef DBUSFRAMEWORK_H
#define DBUSFRAMEWORK_H

#include <QObject>
#include <QString>
#include <QList>
#include <utility>
#include <unordered_map>
#include <tuple>

#include "applicationService/applicationservice.h"

/**
 * @brief The DbusFramework class represents a D-Bus framework for managing services and method calls.
 *
 * This class inherits from QObject and provides functionalities for registering services and calling methods
 * via D-Bus. It includes a router to map service names to D-Bus-related information.
 */
class DbusFramework : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ru.framework.DbusFramework")
public:
    /**
     * @brief Default constructor for the DbusFramework class.
     */
    DbusFramework() = default;

public slots:
    /**
     * @brief Registers a D-Bus service with the specified parameters.
     *
     * This slot is used to register a D-Bus service with the provided name, D-Bus service name, D-Bus path,
     * and D-Bus interface. It adds the information to the internal router for future reference.
     *
     * @param name The name of the service.
     * @param dbusService The D-Bus service name.
     * @param dbusPath The D-Bus path.
     * @param dbusInterface The D-Bus interface.
     */
    void registerService(const QString &name, const QString &dbusService, const QString &dbusPath, const QString &dbusInterface);

    /**
     * @brief Calls a method on a registered D-Bus service with the specified parameters.
     *
     * This slot is used to call a method on a registered D-Bus service with the provided service name,
     * method name, and arguments. It returns the result of the method call as a QVariant.
     *
     * @param serviceName The name of the D-Bus service.
     * @param method The name of the method to be called.
     * @param args The list of arguments to be passed to the method.
     * @return The result of the method call as a QVariant.
     */
    QVariant callMethod(const QString &serviceName, const QString &method, const QStringList &args);

private:
    /**
     * @brief Internal router to map service names to D-Bus-related information.
     */
    std::unordered_map<QString, std::tuple<QString, QString, QString>> router_;
};

#endif // DBUSFRAMEWORK_H
