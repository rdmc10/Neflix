#pragma once
#include "Movie.h"


//TODO: remove
#include "qmainwindow.h"

Movie::Movie()
	: m_type(Movie::Type::Movie)
	, m_name("")
	, m_releaseDate(2022)
	, m_duration("60")
	, m_description("No description available.")
{
}

Movie::Movie(uint32_t id, const Type& type, const std::string& name, const std::vector<std::string>& directors, const std::vector<std::string>& cast, const std::string& country,const std::string& dateAdded, uint16_t releaseDate, const std::string& rating, const std::string& duration,
	const std::vector<std::string>& categories, const std::string& description)
	: m_movieId(id)
	, m_type(type)
	, m_name(name)
	, m_directors(directors)
	, m_cast(cast)
	, m_country(country)
	, m_dateAdded(dateAdded)
	, m_releaseDate(releaseDate)
	, m_rating(rating)
	, m_duration(duration)
	, m_categories(categories)
	, m_description(description)
{
}

Movie::Movie(const Movie& movie)
	:m_movieId(movie.m_movieId)
	, m_type(movie.m_type)
	, m_name(movie.m_name)
	, m_directors(movie.m_directors)
	, m_cast(movie.m_cast)
	, m_country(movie.m_country)
	, m_dateAdded(movie.m_dateAdded)
	, m_releaseDate(movie.m_releaseDate)
	, m_rating(movie.m_rating)
	, m_duration(movie.m_duration)
	, m_categories(movie.m_categories)
	, m_description(movie.m_description)
{
}

Movie::Movie(Movie&& movie)
{
	*this = std::move(movie);
}

Movie& Movie::operator=(Movie&& movie)
{
	m_movieId = movie.GetMovieID();
	m_type = movie.GetMovieType();
	m_name = movie.GetName();
	m_directors = movie.GetDirectors();
	m_cast = movie.GetCast();
	m_country = movie.GetCountry();
	m_dateAdded = movie.GetDateAdded();
	m_releaseDate = movie.GetReleaseDate();
	m_rating = movie.GetRating();
	m_duration = movie.GetDuration();
	m_categories = movie.GetCategories();
	m_description = movie.GetDescription();

	new(&movie) Movie;
	return *this;
}

Movie& Movie::operator=(const Movie& movie)
{
	m_movieId = movie.GetMovieID();
	m_type = movie.GetMovieType();
	m_name = movie.GetName();
	m_directors = movie.GetDirectors();
	m_cast = movie.GetCast();
	m_country = movie.GetCountry();
	m_dateAdded = movie.GetDateAdded();
	m_releaseDate = movie.GetReleaseDate();
	m_rating = movie.GetRating();
	m_duration = movie.GetDuration();
	m_categories = movie.GetCategories();
	m_description = movie.GetDescription();

	return *this;
}

uint32_t Movie::GetMovieID() const
{
	return m_movieId;
}

Movie::Type Movie::GetMovieType() const
{
	return m_type;
}

std::string Movie::GetName() const
{
	return m_name;
}

std::vector<std::string> Movie::GetDirectors() const
{
	return m_directors;
}

std::vector<std::string> Movie::GetCast() const
{
	return m_cast;
}

std::string Movie::GetCountry() const
{
	return m_country;
}

std::string Movie::GetDateAdded() const
{
	return m_dateAdded;
}

uint16_t Movie::GetReleaseDate() const
{
	return m_releaseDate;
}

std::string Movie::GetRating() const
{
	return m_rating;
}

std::string Movie::GetDuration() const
{
	return m_duration;
}

std::vector<std::string> Movie::GetCategories() const
{
	return m_categories;
}

std::string Movie::GetDescription() const
{
	return m_description;
}

void Movie::SetID(const uint32_t& id)
{
	m_movieId = id;
}

void Movie::SetType(const Type& type)
{
	m_type = type;
}

void Movie::SetName(const std::string& name)
{
	m_name = name;
}

void Movie::SetDirectors(const std::vector<std::string>& directors)
{
	m_directors = directors;
}

void Movie::SetCast(const std::vector<std::string>& cast)
{
	m_cast = cast;
}

void Movie::SetCountry(const std::string& country)
{
	m_country = country;
}

void Movie::SetDateAdded(const std::string& dateAdded)
{
	m_dateAdded = dateAdded;
}

void Movie::SetReleaseDate(uint16_t releaseDate)
{
	m_releaseDate = releaseDate;
}

void Movie::SetRating(const std::string& rating)
{
	m_rating = rating;
}

void Movie::SetDuration(const int& duration)
{
	m_duration = duration;
}

void Movie::SetCategories(const std::vector<std::string>& categories)
{
	m_categories = categories;
}

void Movie::SetDescription(const std::string& description)
{
	m_description = description;
}

bool Movie::operator<(const Movie& movie)
{
	return this->m_name < movie.m_name;
}