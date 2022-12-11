#include "UserPreferences.h"

UserPreferences::UserPreferences()
{
}

void UserPreferences::AddMovieLiked(const Movie& movie)
{
	this->m_moviesLiked.push_back(movie);
}

void UserPreferences::AddCategoryLiked(const MovieCategory& movieCategory)
{
	this->m_categoriesLiked.push_back(movieCategory);
}

void UserPreferences::AddActorLiked(const Person& actor)
{
	this->m_actorsLiked.push_back(actor);
}

