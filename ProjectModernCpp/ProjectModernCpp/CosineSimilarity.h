#ifndef cosine_h
#define cosine_h
#include <vector>
#include <unordered_map>
#include "Movie.h"
#include "Cluster.h"

class CosineSimilarity
{
public:
	
	// Constructor

	static std::vector<Movie> GetSimilarMovies(const Movie& movie, const std::vector<Movie>& allMovies);


private:
	static float ComputeCosineSimilarity(const std::vector<float>& a, const std::vector<float>& b);
	static std::vector<float> ComputeNormMovie(const Movie& movie);


private:
	std::vector<Cluster> m_clusters;
};
#endif
