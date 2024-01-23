#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QObject>
#include <QString>


class ApplicationController : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ru.model.SmartCalc")

public:
    ApplicationController() = default;

public slots:
    double calculateExpression(const QString &expression) const;
};

#endif // APPLICATIONCONTROLLER_H
