#pragma once
#include "Person.h"
#include "Movie.h"
class UserPreferences
{
public:
	UserPreferences();
	void AddMovieLiked(const Movie& movie);
	void AddCategoryLiked(const MovieCategory& movieCategory);
	void AddActorLiked(const Person& actor);
	std::vector<Movie> GetMoviesLiked();
	std::vector<MovieCategory> GetCategoriesLiked();
	std::vector<Person> GetPersonLiked();

private:
	std::vector<Movie> m_moviesLiked;
	std::vector<MovieCategory> m_categoriesLiked;
	std::vector<Person> m_actorsLiked;
};

