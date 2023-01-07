#pragma once

#include <string>
#include <cstdint>
#include <unordered_set>
#include <boost/algorithm/string.hpp>

namespace sql = sqlite_orm;

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

	CSVMovie() = default;

};

inline auto createMovieStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"movies",
			sql::make_column("id", &CSVMovie::m_movieId, sql::autoincrement(), sql::primary_key()),
			sql::make_column("type", &CSVMovie::m_type),
			sql::make_column("name", &CSVMovie::m_name),
			sql::make_column("directors", &CSVMovie::m_directors),
			sql::make_column("cast", &CSVMovie::m_cast),
			sql::make_column("country", &CSVMovie::m_country),
			sql::make_column("date_added", &CSVMovie::m_dateAdded),
			sql::make_column("release_date", &CSVMovie::m_releaseDate),
			sql::make_column("rating", &CSVMovie::m_rating),
			sql::make_column("duration", &CSVMovie::m_duration),
			sql::make_column("categories", &CSVMovie::m_categories),
			sql::make_column("description", &CSVMovie::m_description)

		)
	);
}


inline std::vector<std::string> SplitString (const std::string& string,const std::string& separator) {
    std::vector<std::string> strs;
    boost::split(strs, string, boost::is_any_of(separator));

    return strs;
}

using MovieDatabase = decltype(createMovieStorage(""));

inline std::unordered_set<std::string> GetCategoriesFromDatabase() {
    std::unordered_set<std::string> allCategories;
    MovieDatabase m_db = createMovieStorage("database.db");
    auto categoriesFromDb = m_db.select(sql::columns(&CSVMovie::m_categories));

    for (const auto& categories : categoriesFromDb) {
        std::string line = std::get<0>(categories);
        std::vector<std::string> separatedLine = SplitString(line, ",");
        for (auto& category : separatedLine) {
            if (category[0] == ' ')category.erase(0, 1);
            allCategories.insert(category);
        }
    }

    return allCategories;
}
