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

void Person::SetMovie(const std::set<Movie> movieList)
{
	m_movieList = movieList;
}
