#include <QApplication>
#include "../include/dbus_framework/dbusframework.h"
#include "../include/dbus_framework/frameworkAdaptor.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);



  auto controller = std::make_unique<DbusFramework>();
  auto adaptor = std::make_unique<DbusFrameworkAdaptor>(controller.get());
  auto service = std::make_unique<ApplicationService>(adaptor.get());
  controller->registerService("CreditCalc",
                              "ru.credit.CreditCalc",
                              "/ru/credit/CreditCalc",
                              "ru.credit.CreditCalc");
  controller->registerService("SmartCalc",
                              "ru.model.SmartCalc",
                              "/ru/model/SmartCalc",
                              "ru.model.SmartCalc");
  MainWindow w(controller);
  w.show();
  return a.exec();
}
