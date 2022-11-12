#include "User.h"

uint32_t User::m_userNumber = 1;

User::User()
	:m_userId(m_userNumber++)
	,m_username("")
	,m_firstName("")
	,m_lastName("")
	,m_email("")
	,m_birthDate("")
{

}

User::User(const uint32_t& id, const std::string& userName, const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& birthDate)
	:m_userId(m_userNumber++),
	m_username(userName),
	m_firstName(firstName),
	m_lastName(lastName),
	m_email(email),
	m_birthDate(birthDate)
{

}

User::User(const User& user)
	:m_userId(user.m_userId)
	, m_username(user.m_username)
	, m_firstName(user.m_firstName)
	, m_lastName(user.m_lastName)
	, m_email(user.m_email)
	, m_birthDate(user.m_birthDate)
{

}

uint32_t User::GetID() const
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

void User::SetID(const uint32_t& id)
{
	m_userId = id;
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
