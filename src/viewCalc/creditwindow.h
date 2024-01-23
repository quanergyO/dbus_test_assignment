#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QMainWindow>
#include "../include/dbus_framework/dbusframework.h"

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreditWindow(std::unique_ptr<DbusFramework> &dbus, QWidget *parent = nullptr);
    ~CreditWindow();

private slots:
    void on_pushButton_calc_credit_clicked();

private:
    Ui::CreditWindow *ui;
    std::unique_ptr<DbusFramework> &dbus_;
};

#endif // CREDITWINDOW_H
