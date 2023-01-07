#include "UserPreferences.h"

UserPreferences::UserPreferences()
{
}

UserPreferences::UserPreferences(const UserPreferences& userPreferences) 
	: m_moviesLiked(userPreferences.m_moviesLiked)
	, m_categoriesLiked(userPreferences.m_categoriesLiked)
{
}

UserPreferences& UserPreferences::operator=(const UserPreferences& userPreferences)
{
	m_moviesLiked = userPreferences.m_moviesLiked;
	m_categoriesLiked = userPreferences.m_categoriesLiked;

	return *this;
}

void UserPreferences::AddMovieLiked(const Movie& movie)
{
	this->m_moviesLiked.push_back(movie);
}

void UserPreferences::AddCategoryLiked(const MovieCategory& movieCategory)
{
	this->m_categoriesLiked.push_back(movieCategory);
}

void UserPreferences::AddRatingsLiked(const std::string& rating)
{
	m_ratingsLiked.push_back(rating);
}

void UserPreferences::AddTypeLiked(const MovieType& type)
{
	m_typeLiked = type;
}


void UserPreferences::SetMoviesLiked(const std::vector<Movie>& moviesLiked)
{
	m_moviesLiked = moviesLiked;
}

void UserPreferences::SetCategoriesLiked(const std::vector<MovieCategory>& categoriesLiked)
{
	m_categoriesLiked = categoriesLiked;
}

void UserPreferences::SetRatingsLiked(const std::vector<std::string>& ratingsLiked)
{
	m_ratingsLiked = ratingsLiked;
}

void UserPreferences::SetTypeLiked(const MovieType& typeLiked)
{
	m_typeLiked = typeLiked;
}


std::vector<Movie> UserPreferences::GetMoviesLiked()
{
	return this->m_moviesLiked;
}

std::vector<MovieCategory> UserPreferences::GetCategoriesLiked()
{
	return this->m_categoriesLiked;
}

