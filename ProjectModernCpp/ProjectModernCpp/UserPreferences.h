#pragma once
#include "Person.h"
#include "Movie.h"
#include "CSVMovie.h"
class UserPreferences
{
public:
	UserPreferences();
	UserPreferences(const UserPreferences& userPreferences);

	UserPreferences& operator=(const UserPreferences& userPreferences);

	void AddMovieLiked(const Movie& movie);
	void AddCategoryLiked(const MovieCategory& movieCategory);
	void AddActorLiked(const Person& actor);
	std::vector<Movie> GetMoviesLiked();
	std::vector<MovieCategory> GetCategoriesLiked();
	std::vector<Person> GetPersonLiked();

	friend inline auto createUserPreferencesStorage(const std::string& filename);

private:
	std::vector<Movie> m_moviesLiked;
	std::vector<MovieCategory> m_categoriesLiked;
	std::vector<Person> m_actorsLiked;
};



inline auto createUserPreferencesStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"movies",
			sql::make_column("type", &UserPreferences::m_moviesLiked),
			sql::make_column("name", &UserPreferences::m_actorsLiked),
			sql::make_column("directors", &UserPreferences::m_categoriesLiked)

		)
	);
}


using UserPreferencesDatabase = decltype(createUserPreferencesStorage(""));