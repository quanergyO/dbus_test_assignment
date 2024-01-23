#include "creditcalccontroller.h"

QStringList CreditCalcController::calculate(const QString &totalLoanAmount,
                                            const QString &term,
                                            const QString &interestRate,
                                            const QString &isAnnuity) const {
  try {
    s21::ModelCreditCalc model;
    model.setData(totalLoanAmount.toStdString(), term.toStdString(),
                  interestRate.toStdString(),
                  isAnnuity == "true" ? true : false);
    auto answer = model.calculate();
    QStringList returnValue;
    for (const auto &string : answer) {
      returnValue.append(QString::fromStdString(string));
    }
    return returnValue;
  } catch (std::exception &e) {
    return {e.what()};
  }
}
