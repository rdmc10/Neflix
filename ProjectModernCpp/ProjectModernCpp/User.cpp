#include "User.h"

User::User()
	:m_userId(0)
	,m_username("")
	,m_firstName("")
	,m_lastName("")
	,m_email("")
	,m_birthDate("")
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
