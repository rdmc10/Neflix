#pragma once
#include <string>
#include <cstdint>
#include <sqlite_orm/sqlite_orm.h>

namespace sql = sqlite_orm;

class User
{
public:
	User();
	User(const std::string& password, const std::string& userName, const std::string& firstName, const std::string& lastName,
		const std::string& email, const std::string& birthDate);
	User(const User& user);

	User& operator=(const User& user);

	uint32_t GetId() const;
	std::string GetUsername() const;
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetEmail() const;
	std::string GetPassword() const;
	std::string GetBirthdate() const;

	void SetId(uint32_t id);
	void SetPassword(const std::string& password);
	void SetUsername(const std::string& username);
	void SetFirstName(const std::string& firstName);
	void SetLastName(const std::string& lastName);
	void SetEmail(const std::string& email);
	void SetBirthDate(const std::string& birthDate);

	friend inline auto createStorage(const std::string& filename);
	friend inline User getUserFromStorage(std::string username);


private:
	uint32_t m_userId;
	std::string m_password;
	std::string m_username;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_email;
	std::string m_birthDate;

	//TODO: categories/favorite actors etc
};


inline auto createStorage(const std::string& filename)
{
	return sql::make_storage(
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
	);
}

inline User getUserFromStorage(std::string username) {

	using namespace sqlite_orm;
	auto m_db = createStorage("database.db");

	User user;

	auto userFromDatabase = m_db.select(sql::columns(&User::m_username, &User::m_password, &User::m_birthDate, &User::m_email, &User::m_firstName, &User::m_lastName, &User::m_userId)
		, sql::where(c(&User::m_username) == username));


	if (userFromDatabase.size() != 0) {
		user.SetUsername(std::get<0>(userFromDatabase.at(0)));
		user.SetPassword(std::get<1>(userFromDatabase.at(0)));
	}
		
	return user;

}

using Database = decltype(createStorage(""));
