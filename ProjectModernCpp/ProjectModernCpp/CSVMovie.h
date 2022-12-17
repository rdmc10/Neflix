#include <string>
#include <cstdint>

struct CSVMovie {

	uint32_t m_movieId;
	std::string m_type;
	std::string m_name;
	std::string m_directors;
	std::string m_cast;
	std::string m_country;
	std::string m_dateAdded;
	uint16_t m_releaseDate;
	std::string m_rating;
	std::string m_duration;
	std::string m_categories; 
	std::string m_description;

	CSVMovie(uint32_t movieId, const std::string& type, const std::string& name, const std::string& directors, const std::string& cast,
		const std::string& country, const std::string& dateAdded, uint16_t releaseDate,
		const std::string& rating, const std::string& duration, const std::string& categories, const std::string& description)
		:m_movieId(movieId),
		m_type(type),
		m_name(name),
		m_directors(directors),
		m_cast(cast),
		m_country(country),
		m_dateAdded(dateAdded),
		m_releaseDate(releaseDate),
		m_rating(rating),
		m_duration(duration),
		m_categories(categories),
		m_description(description)
	{};


};