#include "Person.h"

void Person::SetFirstName(const std::string& firstName)
{
	m_firstName = firstName;
}

void Person::SetLastName(const std::string& lastName)
{
	m_lastName = lastName;
}

void Person::SetRole(const Role& role)
{
	m_role = role;
}

void Person::SetMovie(const std::set<Movie>& movieList)
{
	m_movieList = movieList;
}

std::string Person::GetFirstName() const
{
	return m_firstName;
}

std::string Person::GetLastName() const
{
	return m_lastName;
}

Person::Role Person::GetRole() const
{
	return m_role;
}

std::set<Movie> Person::GetMovieList() const
{
	return m_movieList;
}
