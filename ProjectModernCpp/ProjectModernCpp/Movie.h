#pragma once
#include "Person.h"
#include "MovieCategory.h"
#include <cstdint>
#include <string>
#include <vector>
//#include <unordered_set>

class Movie {

public:

	enum class Type {
		MOVIE,
		SHOW
	};

public:

	Movie();
	Movie(uint32_t id, const Type& type, const std::set<Person>& cast, uint16_t releaseDate, const std::string& rating,
		 uint16_t duration, /*CATEGORIES*/ const std::string& description);
	Movie(const Movie& movie);
	Movie(Movie&& movie);

	Movie& operator=(Movie&& movie);
	Movie& operator=(const Movie& movie);

	uint32_t GetMovieID() const;
	Type GetMovieType() const;
	std::string GetName() const;
	std::set<Person> GetCast() const;
	uint16_t GetReleaseDate() const;
	std::string GetRating() const;
	uint16_t GetDuration() const;
	std::vector<MovieCategory> GetCategories() const;
	std::string GetDescription() const;

	void SetID(const uint32_t& id);
	void SetType(const Type& type);
	void SetName(const std::string& name);
	void SetCast(const std::set<Person>& cast);
	void SetReleaseDate(const uint16_t& releaseDate);
	void SetRating(const std::string& rating);
	void SetDuration(const uint16_t& duration);
	// Setter for categories
	void SetDescription(const std::string& description);

	void AddCategory(const MovieCategory& category);

	bool operator<(const Movie& movie);

private:

	static uint32_t m_movieNumber;
	uint32_t m_movieId;
	Type m_type;
	std::string m_name;
	std::set<Person> m_cast;
	uint16_t m_releaseDate;
	std::string m_rating;
	uint16_t m_duration;
	std::vector<MovieCategory> m_categories; // TODO: replace vector with unordered_set
	std::string m_description;

};

