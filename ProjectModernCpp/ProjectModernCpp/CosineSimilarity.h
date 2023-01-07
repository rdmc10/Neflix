#pragma once
#include <vector>
#include "Movie.h"
#include "Cluster.h"

class CosineSimilarity
{
public:
	
	// Constructor

	std::vector<Movie> GetSimilarMovies(const Movie& movie);


private:
	float ComputeCosineSimilarity(const std::vector<float>& a, const std::vector<float>& b);
	std::vector<float> ComputeNormMovie(const Movie& movie);


private:
	std::vector<Cluster> m_clusters;
	
	std::vector<Movie> m_movies;

};

