#include "ProjectModernCpp.h"
#include <QtWidgets/QApplication>

using namespace sqlite_orm;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProjectModernCpp w;
    w.show();
    return a.exec();
}
