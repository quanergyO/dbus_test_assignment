#include <QCoreApplication>
#include <memory>

#include "../../application/creditCalcApplication/creditcalccontroller.h"
#include "../../application/creditCalcApplication/creditCalcAdaptor.h"
#include "../../include/dbus_framework/applicationService/applicationservice.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto controller = std::make_unique<CreditCalcController>();
    auto adaptor = std::make_unique<CreditCalcAdaptor>(controller.get());
    auto service = std::make_unique<ApplicationService>(adaptor.get());

    return a.exec();
}
