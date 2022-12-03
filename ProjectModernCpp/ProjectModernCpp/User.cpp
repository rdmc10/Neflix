#include "User.h"

User::User()
	:m_username("")
	, m_password("")
	, m_firstName("")
	, m_lastName("")
	, m_email("")
	, m_birthDate("")
{

}

User::User(const std::string& password, const std::string& userName, const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& birthDate)
	:m_password(password),
	m_username(userName),
	m_firstName(firstName),
	m_lastName(lastName),
	m_email(email),
	m_birthDate(birthDate)
{

}

User::User(const User& user)
	:m_username(user.m_username)
	, m_password(user.m_password)
	, m_firstName(user.m_firstName)
	, m_lastName(user.m_lastName)
	, m_email(user.m_email)
	, m_birthDate(user.m_birthDate)
{

}

User& User::operator=(const User& user)
{
	m_password = user.GetPassword();
	m_username = user.GetUsername();
	m_firstName = user.GetFirstName();
	m_lastName = user.GetLastName();
	m_email = user.GetEmail();
	m_birthDate = user.GetBirthdate();

	return *this;
}

std::string User::GetPassword() const
{
	return m_password;
}

uint32_t User::GetId() const
{
	return m_userId;
}

std::string User::GetUsername() const
{
	return m_username;
}

std::string User::GetFirstName() const
{
	return m_firstName;
}

std::string User::GetLastName() const
{
	return m_lastName;
}

std::string User::GetEmail() const
{
	return m_email;
}

std::string User::GetBirthdate() const
{
	return m_birthDate;
}

void User::SetId(uint32_t id)
{
	m_userId = id;
}

void User::SetPassword(const std::string& password)
{
	m_password = password;
}

void User::SetUsername(const std::string& username)
{
	m_username = username;
}

void User::SetFirstName(const std::string& firstName)
{
	m_firstName = firstName;
}

void User::SetLastName(const std::string& lastName)
{
	m_lastName = lastName;
}

void User::SetEmail(const std::string& email)
{
	m_email = email;
}

void User::SetBirthDate(const std::string& birthDate)
{
	m_birthDate = birthDate;
}

