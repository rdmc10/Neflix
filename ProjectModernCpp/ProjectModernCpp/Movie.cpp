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
