#include "User.h"

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
