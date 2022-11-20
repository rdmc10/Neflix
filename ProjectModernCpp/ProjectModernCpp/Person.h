#pragma once
#include <set>
#include <string>

class Movie;

class Person
{
public:
	enum class Role {
		Actor,
		Director
	};

public:

	Person();
	Person(const std::string& firstName, const std::string& lastName, const Role& role,
		const std::set<Movie>& movieList);
	Person(const Person& pers);

	Person& operator=(const Person& person);

	void SetFirstName(const std::string& firstName);
	void SetLastName(const std::string& lastName);
	void SetRole(const Role& role);
	void SetMovie(const std::set<Movie>& movieList);
	std::string GetFirstName() const;
	std::string GetLastName() const;
	Role GetRole() const;
	std::set<Movie> GetMovieList() const;

	bool operator<(const Person& person);

private:
	std::string m_firstName;
	std::string m_lastName;
	Role m_role;
	std::set<Movie> m_movieList;
};

