#pragma once
#include "Person.h"
#include "Movie.h"
class UserPreferences
{
public:
	UserPreferences();
	void AddMovieLiked();
	void AddCategoryLiked();
	void AddActorLiked();
	std::vector<Movie> GetMoviesLiked();
	std::vector<MovieCategory> GetCategoriesLiked();
	std::vector<Person> GetPersonLiked();

private:
	std::vector<Movie> m_moviesLiked;
	std::vector<MovieCategory> m_categoriesLiked;
	std::vector<Person> m_actorsLiked;
};

