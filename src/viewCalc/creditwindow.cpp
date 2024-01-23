#include "creditwindow.h"
#include "ui_creditwindow.h"

CreditWindow::CreditWindow(std::unique_ptr<DbusFramework> &dbus, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CreditWindow), dbus_(dbus) {
  ui->setupUi(this);
  connect(ui->pushButton_calc_credit, SIGNAL(clicked()), this, SLOT(on_pushButton_calc_credit_clicked()));
  setAttribute(Qt::WA_DeleteOnClose);
}

CreditWindow::~CreditWindow() { delete ui; }

void CreditWindow::on_pushButton_calc_credit_clicked() {
    auto reply = dbus_->callMethod("CreditCalc",
                                   "calculate",
                                   QStringList{ui->doubleSpinBox_deposit_amount->text(),
                                               ui->spinBox_term->text(),
                                               ui->spinBox_insert_rate->text(),
                                               ui->comboBox_credit_type->currentIndex() ? "false" : "true"});
    QStringList list = reply.toStringList();
    ui->label_monthly_payment->setText(list[0]);
    ui->label_total_repayment->setText(list[1]);
    ui->label_loan_overpayment->setText(list[2]);
}
