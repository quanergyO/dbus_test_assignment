#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "../include/dbus_framework/dbusframework.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(std::unique_ptr<DbusFramework> &dbus, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void buttons();

    void on_pushButton_equal_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_credit_clicked();

//   void on_pushButton_debit_clicked();

//   void on_pushButton_graph_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<DbusFramework>& dbus_;
    void set_signals();
};
#endif // MAINWINDOW_H
