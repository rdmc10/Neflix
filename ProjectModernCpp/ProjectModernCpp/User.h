#pragma once
#include <string>
#include <cstdint>
class User
{
public:
	uint32_t GetID() const;
	std::string GetUsername() const;
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetEmail() const;
	std::string GetBirthdate() const;

	void SetID(const uint32_t& id);
	void SetUsername(const std::string& username);
	void SetFirstName(const std::string& firstName);
	void SetLastName(const std::string& lastName);
	void SetEmail(const std::string& email);
	void SetBirthDate(const std::string& birthDate);

private:
	uint32_t m_userId;
	std::string m_username;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_email;
	std::string m_birthDate;
	//TODO: categories/favorite actors etc


};

