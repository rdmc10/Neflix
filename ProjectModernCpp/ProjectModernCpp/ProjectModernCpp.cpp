#include <iostream>
#include <sqlite_orm.h>
#include "User.h"

using namespace sqlite_orm;

int main()
{
    User u;
    std::cout << u.GetID();
    std::cout << "ok";
    return 0;
}
