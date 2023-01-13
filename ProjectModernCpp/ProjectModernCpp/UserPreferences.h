#pragma once
#include "Person.h"
#include "Movie.h"
#include "CSVMovie.h"

namespace sql = sqlite_orm;

class UserPreferences
{
private:
	enum class MovieType {
		Movie,
		TV_Show,
		Both
	};
public:
	UserPreferences();
	UserPreferences(const UserPreferences& userPreferences);

	UserPreferences& operator=(const UserPreferences& userPreferences);

	void AddMovieLiked(const Movie& movie);
	void AddCategoryLiked(const MovieCategory& movieCategory);
	void AddRatingsLiked(const std::string& rating);
	void AddTypeLiked(const MovieType& type);

	void SetMoviesLiked(const std::vector<Movie>& moviesLiked);
	void SetCategoriesLiked(const std::vector<MovieCategory>& categoriesLiked);
	void SetRatingsLiked(const std::vector<std::string>& ratingsLiked);
	void SetTypeLiked(const MovieType& typeLiked);

	std::vector<Movie> GetMoviesLiked();
	std::vector<MovieCategory> GetCategoriesLiked();
	std::vector<std::string> GetRatingsLiked();
	MovieType GetTypeLiked();

	//friend inline auto createUserPreferencesStorage(const std::string& filename);

private:
	std::vector<Movie> m_moviesLiked;
	std::vector<MovieCategory> m_categoriesLiked;
	std::vector<std::string> m_ratingsLiked;
	MovieType m_typeLiked;
};

struct Preferences {

	int m_user_id;
	std::string m_preferencesMoviesLiked;
	std::string m_preferencesRatingsLiked;
	std::string m_preferencesCategoriesLiked;
	std::string m_preferencesTypeLiked;

	Preferences() {
		m_preferencesCategoriesLiked = "";
		m_preferencesRatingsLiked = "";
		m_preferencesMoviesLiked = "";
		m_preferencesTypeLiked = "";
	}
	Preferences(int id) {
		m_user_id = id;
		m_preferencesCategoriesLiked = "";
		m_preferencesMoviesLiked = "";
		m_preferencesRatingsLiked = "";
		m_preferencesTypeLiked = "";
	}
	Preferences(int id, std::string movies, std::string ratings, std::string categories, std::string type) {
		m_user_id = id;
		m_preferencesCategoriesLiked = categories;
		m_preferencesMoviesLiked = movies;
		m_preferencesRatingsLiked = ratings;
		m_preferencesTypeLiked = type;
	}
};

inline auto createUserPreferencesStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"user_preferences",
			sql::make_column("user_id", &Preferences::m_user_id),
			sql::make_column("movies", &Preferences::m_preferencesMoviesLiked),
			sql::make_column("rating", &Preferences::m_preferencesRatingsLiked),
			sql::make_column("categories", &Preferences::m_preferencesCategoriesLiked),
			sql::make_column("type", &Preferences::m_preferencesTypeLiked)
		)
	);
}

inline bool checkIfUserPreferencesExist(int id) {
	using namespace sqlite_orm;
	auto m_db = createUserPreferencesStorage("database.db");
	auto userPref = m_db.select(sql::columns(&Preferences::m_user_id)
		, sql::where(c(&Preferences::m_user_id) == id));


	return userPref.size() != 0;

}


using UserPreferencesDatabase = decltype(createUserPreferencesStorage(""));