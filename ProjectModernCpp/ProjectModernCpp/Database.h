#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <sqlite_orm/sqlite_orm.h>
#include "User.h"

namespace sql = sqlite_orm;

inline auto createStorage(const std::string& filename)
{
	sql::make_storage(filename,
		sql::make_storage(
			filename,
			sql::make_table(
				"users",
				sql::make_column("id", &User::m_userId, sql::autoincrement(), sql::primary_key()),
				sql::make_column("username", &User::m_username),
				sql::make_column("first_name", &User::m_firstName),
				sql::make_column("last_name", &User::m_lastName),
				sql::make_column("email", &User::m_email),
				sql::make_column("password", &User::m_password),
				sql::make_column("birthdate", &User::m_birthDate)
			)
		)
	)
}


class database
{
public:
	void CSVReadFile(const std::string& csvPath);

private:
	void CSVReadLine(std::vector<std::string>& movieColumns, const std::string& line);
};

