#pragma once
#include "Person.h"
#include "MovieCategory.h"
#include <cstdint>
#include <string>
#include <vector>
#include <sqlite_orm/sqlite_orm.h>
#include <fstream>

//#include <unordered_set>

namespace sql = sqlite_orm;

class Movie {

public:

	enum class Type {
		MOVIE,
		SHOW
	};

public:

	Movie();
	Movie(uint32_t id, const Type& type, const std::string& name, const std::vector<Person>& directors, const std::set<Person>& cast,const std::string& country,const std::string& dateAdded, uint16_t releaseDate, const std::string& rating,
		 uint16_t duration, const std::vector<std::string>& categories, const std::string& description);
	Movie(const Movie& movie);
	Movie(Movie&& movie);

	Movie& operator=(Movie&& movie);
	Movie& operator=(const Movie& movie);

	uint32_t GetMovieID() const;
	Type GetMovieType() const;
	std::string GetName() const;
	std::vector<Person> GetDirectors() const;
	std::set<Person> GetCast() const;
	std::string GetCountry() const;
	std::string GetDateAdded() const;
	uint16_t GetReleaseDate() const;
	std::string GetRating() const;
	uint16_t GetDuration() const;
	std::vector<std::string> GetCategories() const;
	std::string GetDescription() const;

	void SetID(const uint32_t& id);
	void SetType(const Type& type);
	void SetName(const std::string& name);
	void SetDirectors(const std::vector<Person>& directors);
	void SetCast(const std::set<Person>& cast);
	void SetCountry(const std::string& country);
	void SetDateAdded(const std::string& dateAdded);
	void SetReleaseDate(uint16_t releaseDate);
	void SetRating(const std::string& rating);
	void SetDuration(const uint16_t& duration);
	void SetCategories(const std::vector<std::string>& categories);
	void SetDescription(const std::string& description);

	bool operator<(const Movie& movie);

	friend inline auto createMovieStorage(const std::string& filename);

private:

	uint32_t m_movieId;
	Type m_type;
	std::string m_name;
	std::vector<Person> m_directors;
	std::set<Person> m_cast;
	std::string m_country;
	std::string m_dateAdded;
	uint16_t m_releaseDate;
	std::string m_rating;
	uint16_t m_duration;
	std::vector<std::string> m_categories;
	std::string m_description;

};



