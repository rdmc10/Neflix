#pragma once
#include "Movie.h"

uint32_t Movie::m_movieNumber = 1;

Movie::Movie()
	:m_movieId(m_movieNumber++)
	, m_type(Movie::Type::MOVIE)
	, m_releaseDate(2022)
	, m_duration(60)
	, m_description("No description available.")
{
}

Movie::Movie(const uint32_t& id, const Type& type, const std::set<Person>& cast, const uint16_t releaseDate, const uint16_t duration,
	std::string description)
	: m_movieId(m_movieNumber++)
	, m_type(type)
	, m_cast(cast)
	, m_releaseDate(releaseDate)
	, m_duration(duration)
	, m_description(description)
{
}

Movie::Movie(const Movie& movie)
	:m_movieId(movie.m_movieId)
	, m_type(movie.m_type)
	, m_cast(movie.m_cast)
	, m_releaseDate(movie.m_releaseDate)
	, m_duration(movie.m_duration)
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
	m_cast = movie.GetCast();
	m_releaseDate = movie.GetReleaseDate();
	m_duration = movie.GetDuration();
	m_description = movie.GetDescription();

	new(&movie) Movie;
	return *this;
}

Movie& Movie::operator=(const Movie& movie)
{
	m_movieId = movie.GetMovieID();
	m_type = movie.GetMovieType();
	m_cast = movie.GetCast();
	m_releaseDate = movie.GetReleaseDate();
	m_duration = movie.GetDuration();
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

std::set<Person> Movie::GetCast() const
{
	return m_cast;
}

uint16_t Movie::GetReleaseDate() const
{
	return m_releaseDate;
}

uint16_t Movie::GetDuration() const
{
	return m_duration;
}

std::vector<MovieCategory> Movie::GetCategories() const
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

void Movie::SetCast(const std::set<Person>& cast)
{
	m_cast = cast;
}

void Movie::SetReleaseDate(const uint16_t& releaseDate)
{
	m_releaseDate = releaseDate;
}

void Movie::SetDuration(const uint16_t& duration)
{
	m_duration = duration;
}

void Movie::SetDescription(const std::string& description)
{
	m_description = description;
}

void Movie::AddCategory(const MovieCategory& category)
{
	m_categories.push_back(category);
}

bool Movie::operator<(const Movie& movie)
{
	return this->m_name < movie.m_name;
}