/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp ru.model.CreditCalc.xml -i creditcalccontroller.h -a creditCalcAdaptor
 *
 * qdbusxml2cpp is Copyright (C) 2023 The Qt Company Ltd and other contributors.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef CREDITCALCADAPTOR_H
#define CREDITCALCADAPTOR_H

#include <QtCore/QObject>
#include <QDBusAbstractAdaptor>
#include "creditcalccontroller.h"
#include <QtCore/qcontainerfwd.h>

/*
 * Adaptor class for interface ru.credit.CreditCalc
 */
class CreditCalcAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "ru.credit.CreditCalc")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"ru.credit.CreditCalc\">\n"
"    <method name=\"calculate\">\n"
"      <arg direction=\"out\" type=\"as\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"totalLoanAmount\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"term\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"interestRate\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"isAnnuity\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    CreditCalcAdaptor(QObject *parent);
    virtual ~CreditCalcAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    QStringList calculate(const QString &totalLoanAmount, const QString &term, const QString &interestRate, const QString &isAnnuity);
Q_SIGNALS: // SIGNALS
};

#endif