#pragma once
#include "Movie.h"
#include <set>
#include <string>
class Person
{
public:
	enum class Role {
		Actor,
		Director
	};
private:
	std::string m_firstName;
	std::string m_lastName;
	Role m_role;
	std::set<Movie> m_movieList;
};

