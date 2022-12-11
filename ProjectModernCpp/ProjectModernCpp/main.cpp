#include "ProjectModernCpp.h"
#include <QtWidgets/QApplication>
#include "User.h"
#include <sqlite_orm/sqlite_orm.h>
#include "Movie.h"
#include "Register.h"
#include "Database.h"

using namespace sqlite_orm;
int main(int argc, char *argv[])
{
    database db;
    db.CSVReadFile("netflix_titles.csv");

    QApplication a(argc, argv);
    ProjectModernCpp w;
    w.show();
    return a.exec();
}
