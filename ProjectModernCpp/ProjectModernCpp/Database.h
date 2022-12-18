#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <sqlite_orm/sqlite_orm.h>
#include "User.h"
#include "CSVMovie.h"

namespace sql = sqlite_orm;

class database
{

	MovieDatabase m_db = createMovieStorage("database.db");

public:

	std::vector<std::vector<std::string>> readCSV(const std::string&);
	std::vector<std::string> readCSVRow(const std::string& row);

	void PopulateStorage(std::vector<CSVMovie> movies);
	int GetMovieCount();
};

