#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <sqlite_orm/sqlite_orm.h>
#include "User.h"

namespace sql = sqlite_orm;

namespace database
{
	std::vector<std::vector<std::string>> readCSV(const std::string&);
	std::vector<std::string> readCSVRow(const std::string& row);
};

