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

Movie::Movie(const uint32_t& id, const Type& type, const uint16_t releaseDate, const uint16_t duration,
	std::string description)
	: m_movieId(id)
	, m_type(type)
	, m_releaseDate(releaseDate)
	, m_duration(duration)
	, m_description(description)
{
}

Movie::Movie(const Movie& movie)
	:m_movieId(movie.m_movieId)
	, m_type(movie.m_type)
	, m_releaseDate(movie.m_releaseDate)
	, m_duration(movie.m_duration)
	, m_description(movie.m_description)
{
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

uint16_t Movie::GetReleaseDate() const
{
	return m_releaseDate;
}

uint16_t Movie::GetDuration() const
{
	return m_duration;
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
