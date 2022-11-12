#pragma once
#include <cstdint>
#include <string>

class Movie {

public:

	enum class Type {
		MOVIE,
		SHOW
	};

public:

	Movie();
	Movie(const uint32_t& id, const Type& type, /*ACTORS*/ const uint16_t releaseDate, const uint16_t duration,
		/*CATEGORIES*/ std::string description);
	Movie(const Movie& movie);

	uint32_t GetMovieID() const;
	Type GetMovieType() const;
	std::string GetName() const;
	// Getter for actors
	uint16_t GetReleaseDate() const;
	uint16_t GetDuration() const;
	// Getter for categories
	std::string GetDescription() const;

	void SetID(const uint32_t& id);
	void SetType(const Type& type);
	void SetName(const std::string& name);
	// Setter for actors;
	void SetReleaseDate(const uint16_t& releaseDate);
	void SetDuration(const uint16_t& duration);
	// Setter for categories
	void SetDescription(const std::string& description);

private:

	static uint32_t m_movieNumber;
	uint32_t m_movieId;
	Type m_type;
	std::string m_name;
	// TODO: List of actors in a movie(cast)
	uint16_t m_releaseDate;
	uint16_t m_duration;
	// TODO: List of categories in a movie
	std::string m_description;

};