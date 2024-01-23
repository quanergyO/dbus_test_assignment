#ifndef CREDITCALCCONTROLLER_H
#define CREDITCALCCONTROLLER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <modelcreditcalc.h>

class CreditCalcController : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ru.credit.CreditCalc")
public:
    explicit CreditCalcController() = default;

public slots:
    QStringList calculate(const QString &totalLoanAmount,
                          const QString &term,
                          const QString &interestRate,
                          const QString &isAnnuity) const;
};

#endif // CREDITCALCCONTROLLER_H
