#include "MovieReview.h"

uint32_t MovieReview::GetMovieId() const
{
	return m_movieId;
}

uint32_t MovieReview::GetUserId() const
{
	return m_userId;
}

std::atomic_bool MovieReview::GetReview() const
{
	return std::atomic_bool(); // return m_review doesn't work
}

void MovieReview::SetMovieId(const uint32_t& movieId)
{
	m_movieId = movieId;
}

void MovieReview::SetUserId(const uint32_t& userId)
{
	m_userId = userId;
}

void MovieReview::SetReview(const std::atomic_bool& review)
{
	//m_review = review; doesn't work with std::atomic_bool
}
