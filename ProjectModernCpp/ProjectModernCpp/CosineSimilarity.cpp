#include "CosineSimilarity.h"

std::vector<Movie> CosineSimilarity::GetSimilarMovies(const Movie& movie)
{
	std::vector<Movie> similarMovies;
	std::vector<float> normedMovie = ComputeNormMovie(movie);
	for (const auto& movie : m_movies) {
		float similarity = ComputeCosineSimilarity(normedMovie, ComputeNormMovie(movie));
		if (similarity > 0.95)
			similarMovies.emplace_back(movie);
	}
	return similarMovies;
}

float CosineSimilarity::ComputeCosineSimilarity(const std::vector<float>& a, const std::vector<float>& b)
{
	float sumAB = .0f;
	float sumA2 = .0f;
	float sumB2 = .0f;

	for (size_t i = 0; i < a.size(); i++) {
		sumAB += a[i] * b[i];
		sumA2 += std::pow(a[i], 2);
		sumB2 += std::pow(b[i], 2);
	}
	return sumAB / (sqrt(sumA2) * sqrt(sumB2));
}

std::vector<float> CosineSimilarity::ComputeNormMovie(const Movie& movie)
{
	return std::vector<float>();
}
