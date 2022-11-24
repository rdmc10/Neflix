#include "ProjectModernCpp.h"
#include <QtWidgets/QApplication>
#include "User.h"
#include <sqlite_orm/sqlite_orm.h>
#include "Movie.h"

using namespace sqlite_orm;
int main(int argc, char *argv[])
{
    Movie m;
    User u;
    u.SetBirthDate("asd");
    QApplication a(argc, argv);
    ProjectModernCpp w;
    w.show();
    return a.exec();
}
