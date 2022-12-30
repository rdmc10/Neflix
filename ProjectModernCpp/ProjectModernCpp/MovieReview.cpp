#include "MovieReview.h"

MovieReview::MovieReview() 
	: m_review(true)
	, m_userId(0)
	, m_movieId(0)
{
}

MovieReview::MovieReview(const uint32_t& movieId, const uint32_t& userId, const bool& review)
	: m_review(review)
	, m_userId(userId)
	, m_movieId(movieId)
{
}

uint32_t MovieReview::GetMovieId() const
{
	return m_movieId;
}

uint32_t MovieReview::GetUserId() const
{
	return m_userId;
}

bool MovieReview::GetReview() const
{
	return m_review;
}

void MovieReview::SetMovieId(const uint32_t& movieId)
{
	m_movieId = movieId;
}

void MovieReview::SetUserId(const uint32_t& userId)
{
	m_userId = userId;
}

void MovieReview::SetReview(const bool& review)
{
	m_review = review;
}
