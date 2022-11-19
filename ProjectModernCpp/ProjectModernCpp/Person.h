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

public:

	void SetFirstName(const std::string& firstName);
	void SetLastName(const std::string& lastName);
	void SetRole(const Role& role);
	void SetMovie(const std::set<Movie>& movieList);
	std::string GetFirstName() const;
	std::string GetLastName() const;
	Role GetRole() const;
	std::set<Movie> GetMovieList() const;

private:
	std::string m_firstName;
	std::string m_lastName;
	Role m_role;
	std::set<Movie> m_movieList;
};

