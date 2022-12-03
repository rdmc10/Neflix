#pragma once
#include <string>
#include <cstdint>
#include <sqlite_orm/sqlite_orm.h>

namespace sql = sqlite_orm;

class User
{
public:
	User();
	User(const uint32_t& id, const std::string& password, const std::string& userName, const std::string& firstName, const std::string& lastName,
		const std::string& email, const std::string& birthDate);
	User(const User& user);

	User& operator=(const User& user);

	uint32_t GetID() const;
	std::string GetUsername() const;
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetEmail() const;
	std::string GetPassword() const;
	std::string GetBirthdate() const;

	void SetID(const uint32_t& id);
	void SetPassword(const std::string& password);
	void SetUsername(const std::string& username);
	void SetFirstName(const std::string& firstName);
	void SetLastName(const std::string& lastName);
	void SetEmail(const std::string& email);
	void SetBirthDate(const std::string& birthDate);


private:
	static uint32_t m_userNumber;
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
			sql::make_column("id", &User::GetID, &User::SetID, sql::autoincrement(), sql::primary_key()),
			sql::make_column("username", &User::GetUsername, &User::SetUsername),
			sql::make_column("first_name", &User::GetFirstName, &User::SetFirstName),
			sql::make_column("last_name", &User::GetLastName, &User::SetLastName),
			sql::make_column("email", &User::GetEmail, &User::SetEmail),
			sql::make_column("password", &User::GetPassword, &User::SetPassword),
			sql::make_column("birthdate", &User::GetBirthdate, &User::SetBirthDate)
		)
	);
}

using UserCreateStorage = decltype(createStorage(""));
