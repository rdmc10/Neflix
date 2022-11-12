#pragma once
#include "Movie.h"

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
