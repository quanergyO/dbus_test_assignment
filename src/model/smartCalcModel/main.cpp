#include <QCoreApplication>
#include <memory>

#include "../../application/smartCalcApplication/applicationcontroller.h"
#include "../../application/smartCalcApplication/controllerAdaptor.h"
#include "../../include/dbus_framework/applicationService/applicationservice.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  auto controller = std::make_unique<ApplicationController>();
  auto adaptor = std::make_unique<SmartCalcAdaptor>(controller.get());
  auto sevice = std::make_unique<ApplicationService>(adaptor.get());

  return a.exec();
}
