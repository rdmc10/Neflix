#include "CosineSimilarity.h"

std::unordered_map<std::string, float> CategoryMapping = {
	{ "Movies",								0.0f	},

	{ "Dramas",								1.0f	},
	{ "Documentaries",					   12.5f	},
	{ "Comedies",							6.0f	},
	{ "Horror Movies",						5.0f	},
	{ "Independent Movies",				   18.0f	},
	{ "Children & Family Movies",			8.0f	},
	{ "International Movies",			   14.5f	},
	{ "Cult Movies",					   11.5f	},
	{ "Anime Features",					   19.0f	},
	{ "Thrillers",							4.0f	},
	{ "Romantic Movies",					2.0f	},
	{ "Music & Musicals",				   15.0f	},
	{ "Sci-Fi & Fantasy",					9.5f	},
	{ "Action & Adventure",					8.5f	},
	{ "Classic Movies",					   10.5f	},
	{ "Sports Movies",					   14.25f	},
	{ "Faith & Spirituality",			   16.0f    },
	{ "LGBTQ Movies",					   18.5f	},
	{ "Stand-Up Comedy",					7.0f	},
//	--------------------------------------------------
	{ "TV Shows",			 				0.0f	},

	{ "TV Dramas",							1.5f	},
	{ "Docuseries",						   13.0f	},
	{ "Crime TV Shows",						3.5f	},
	{ "TV Comedies",						6.5f	},
	{ "TV Action & Adventure",				9.0f	},
	{ "International TV Shows",			   14.0f	},
	{ "TV Mysteries",						3.0f	},
	{ "Classic & Cult TV",				   11.0f	},
	{ "Reality TV",						   13.5f	},
	{ "Romantic TV Shows",					2.5f	},
	{ "TV Horror",							5.5f	},
	{ "Science & Nature TV",			   12.0f	},
	{ "British TV Shows",				   16.5f	},
	{ "Spanish-Language TV Shows",		   17.0f	},
	{ "TV Sci-Fi & Fantasy",			   10.0f	},
	{ "TV Thrillers",						4.5f	},
	{ "Kids' TV",						   20.5f	},
	{ "Teen TV Shows",					   20.0f	},
	{ "Anime Series",					   19.5f	},
	{ "Korean TV Shows",				   17.5f	},
	{ "Stand-Up Comedy & Talk Shows",		7.5f	}
};

std::unordered_map<std::string, float> TypeMapping = {
	{ "Movie",		1.0f    },
	{ "TV Show",    2.0f    }
};

std::unordered_map<std::string, float> RatingMapping = {
	{ "TV-G",		 1.0f },
	{ "TV-14",		 3.5f },
	{ "PG-13",		 4.0f },
	{ "PG",			 4.5f },
	{ "TV-MA",		 7.0f },
	{ "TV-PG",		4.25f },
	{ "R",			 7.5f },
	{ "TV-Y",		 2.0f },
	{ "TV-Y7",		 2.5f },
	{ "G",			 1.5f },
	{ "NC-17",		 4.0f },
	{ "UR",			10.0f },
	{ "NR",			10.5f },
	{ "TV-Y7-FV",	 3.0f }
};

std::vector<Movie> CosineSimilarity::GetSimilarMovies(const Movie& userMovie, const std::vector<Movie>& allMovies)
{
	std::vector<Movie> similarMovies;
	std::vector<float> normedMovie = ComputeNormMovie(userMovie);
	for (const auto& movie : allMovies) {
		if (movie.GetMovieID() == userMovie.GetMovieID())continue;
		float similarity = ComputeCosineSimilarity(normedMovie, ComputeNormMovie(movie));
		if (similarity > 0.99999f)
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
	std::vector<float> result;

	float categoryNorm = 0.f;

	for (const std::string& categ : movie.GetCategories()) {
		categoryNorm += CategoryMapping[categ];
	}
	categoryNorm /= movie.GetCategories().size();
	result.push_back(categoryNorm);

	float typeNorm = 0.f;

	std::string movieType = movie.GetMovieType() == Movie::Type::Movie ? "Movie" : "TV Show";
	typeNorm += TypeMapping[movieType];
	result.push_back(typeNorm);

	float ratingNorm = 0.f;

	for (const auto& rating : movie.GetCategories()) {
		ratingNorm += RatingMapping[rating];
	}
	ratingNorm /= movie.GetCategories().size();
	result.push_back(ratingNorm);

	return result;
}
