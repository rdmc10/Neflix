#pragma once
#include "Person.h"
#include "Movie.h"
#include "CSVMovie.h"
class UserPreferences
{
private:
	enum class MovieType {
		Movie,
		TV_Show,
	};
public:
	UserPreferences();
	UserPreferences(const UserPreferences& userPreferences);

	UserPreferences& operator=(const UserPreferences& userPreferences);

	void AddMovieLiked(const Movie& movie);
	void AddCategoryLiked(const MovieCategory& movieCategory);

	void SetMoviesLiked(const std::vector<Movie>& moviesLiked);
	void SetCategoriesLiked(const std::vector<MovieCategory>& categoriesLiked);

	std::vector<Movie> GetMoviesLiked();
	std::vector<MovieCategory> GetCategoriesLiked();

	friend inline auto createUserPreferencesStorage(const std::string& filename);

private:
	std::vector<Movie> m_moviesLiked;
	std::vector<MovieCategory> m_categoriesLiked;
	std::vector<std::string> m_ratingsLiked;
	MovieType m_typeLiked;
};



inline auto createUserPreferencesStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"user_preferences",
			sql::make_column("user_id", &UserPreferences::m_moviesLiked),
			sql::make_column("movies", &UserPreferences::m_moviesLiked),
			sql::make_column("rating", &UserPreferences::m_ratingsLiked),
			sql::make_column("categories", &UserPreferences::m_categoriesLiked),
			sql::make_column("type", &UserPreferences::m_typeLiked)
		)
	);
}


using UserPreferencesDatabase = decltype(createUserPreferencesStorage(""));