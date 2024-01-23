#ifndef APPLICATIONSERVICE_H
#define APPLICATIONSERVICE_H

#include <tuple>
#include <QString>
#include <QtDBus/QDBusAbstractAdaptor>

class ApplicationService : public QDBusAbstractAdaptor
{
    Q_OBJECT

    Q_CLASSINFO("D-Bus Interface", DBUS_INTERFACE)

public:
    explicit ApplicationService(QObject *parent = nullptr);
    ~ApplicationService() override;

    static bool isRegistered(const QString &dbusService);
    static QString getService() noexcept;
    static QString getPath() noexcept;
    static QString getInterface() noexcept;

public slots:
    static QVariant updateApplicationArgs(const std::tuple<QString, QString, QString> &applicationDbusData,
                                          const QString &method,
                                          const QStringList &arguments);
};


#endif // APPLICATIONSERVICE_H
