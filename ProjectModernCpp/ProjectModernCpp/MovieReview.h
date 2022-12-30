#pragma once
#include <cstdint>
#include <iostream>

class MovieReview
{
public:
	MovieReview();
	MovieReview(const uint32_t& movieId, const uint32_t& userId, const bool& review);

	uint32_t GetMovieId() const;
	uint32_t GetUserId() const;
	bool GetReview() const;

	void SetMovieId(const uint32_t& movieId);
	void SetUserId(const uint32_t& userId);
	void SetReview(const bool& review);

private:
	uint32_t m_movieId;
	uint32_t m_userId;
	bool m_review;
};

