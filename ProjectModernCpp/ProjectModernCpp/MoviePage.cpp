#include "MoviePage.h"
#include "CosineSimilarity.h"

MoviePage::MoviePage(const User& user, CSVMovie movie, QWidget *parent)
	:
	m_user(user),
	m_movie(movie),
	QMainWindow(parent)
	, moviePage(new Ui::MoviePageClass())
{
	moviePage->setupUi(this);

	connect(moviePage->button_return, SIGNAL(clicked()), SLOT(onReturnButtonClick()));
	connect(moviePage->button_like, SIGNAL(clicked()), SLOT(onLikeButtonClick()));
	connect(moviePage->button_wishlist, SIGNAL(clicked()), SLOT(onWishlistButtonClick()));
	connect(moviePage->button_watched, SIGNAL(clicked()), SLOT(onWatchedButtonClick()));

	connect(moviePage->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onMovieRecommandationClick(QListWidgetItem*)));

	moviePage->label_movieName->setText(QString::fromStdString(movie.m_name + " ( " + movie.m_type + " - " + std::to_string(movie.m_releaseDate) + " )"));
	moviePage->label_movieName->setAlignment(Qt::AlignCenter);

	moviePage->label_movieRating->setText(moviePage->label_movieRating->text() + " " + QString::fromStdString(movie.m_rating));

	moviePage->textBrowser_movieDescription->setText(QString::fromStdString(movie.m_description));

	std::vector<std::string> categories = SplitString(movie.m_categories, ",");
	for (auto cat : categories) {
		if (std::isspace(cat[0]))
			cat.erase(0, 1);
		moviePage->listWidget_movieCategories->addItem(QString::fromStdString(cat));
	}
	
	std::vector<std::string> cast = SplitString(movie.m_cast, ",");
	for (auto member : cast) {
		if (std::isspace(member[0]))
			member.erase(0, 1);
		moviePage->listWidget_movieCast->addItem(QString::fromStdString(member));
	}

	std::vector<std::string> directors = SplitString(movie.m_directors, ",");
	for (auto director : directors) {
		if (std::isspace(director[0]))
			director.erase(0, 1);
		moviePage->listWidget_movieDirectors->addItem(QString::fromStdString(director));
	}

	std::vector<std::string> countries = SplitString(movie.m_country, ",");
	for (auto country : countries) {
		if (std::isspace(country[0]))
			country.erase(0, 1);
		moviePage->listWidget_movieCountries->addItem(QString::fromStdString(country));
	}

	database db;

	using namespace sqlite_orm;
	auto movieDB = createMovieStorage("database.db");
    auto userMovieRelationsDB = createUserMovieRelationsDB("database.db");
	auto movieData = movieDB.select(sql::columns(&CSVMovie::m_movieId)
		, sql::where(c(&CSVMovie::m_name) == m_movie.m_name));

	uint32_t movieID = std::get<0>(movieData.at(0));
	auto userMovieRelations = userMovieRelationsDB.select(sql::columns(&Relations::m_user_id, &Relations::m_movie_id, &Relations::m_isWatched,
		&Relations::m_isOnWishlist, &Relations::m_isLiked)
		, sql::where(c(&Relations::m_movie_id) == movieID));

	auto moviesFromDb = movieDB.select(sql::columns(&CSVMovie::m_movieId, &CSVMovie::m_type, &CSVMovie::m_name, &CSVMovie::m_directors, &CSVMovie::m_cast, &CSVMovie::m_country,
		&CSVMovie::m_dateAdded, &CSVMovie::m_releaseDate, &CSVMovie::m_rating, &CSVMovie::m_duration, &CSVMovie::m_categories, &CSVMovie::m_description)
		, sql::where(c(&CSVMovie::m_name) == m_movie.m_name));
	std::vector<Movie> moviesData;


		Movie tmp(
			std::get<0>(moviesFromDb[0])
			, std::get<1>(moviesFromDb[0]) == "Movie" ? Movie::Type::Movie : Movie::Type::Show
			, std::get<2>(moviesFromDb[0])
			, ParseString(std::get<3>(moviesFromDb[0]))
			, ParseString(std::get<4>(moviesFromDb[0]))
			, std::get<5>(moviesFromDb[0])
			, std::get<6>(moviesFromDb[0])
			, std::get<7>(moviesFromDb[0])
			, std::get<8>(moviesFromDb[0])
			, std::get<9>(moviesFromDb[0])
			, ParseString(std::get<10>(moviesFromDb[0]))
			, std::get<11>(moviesFromDb[0])
		);
	

	std::vector<Movie> movies = CosineSimilarity::GetSimilarMovies(tmp, db.GetMoviesData());

	for (uint32_t i = 0; i < 5 % movies.size(); ++i) {
		moviePage->listWidget->addItem(QString::fromStdString(movies[i].GetName())); // recommendations
	}
	
	if (userMovieRelations.size() != 0) {
		if (std::get<2>(userMovieRelations[0]) == true) 
			moviePage->button_watched->setText(QString("Unwatch"));
		if(std::get<3>(userMovieRelations[0]) == true)
			moviePage->button_wishlist->setText(QString("Unwish"));
		if(std::get<4>(userMovieRelations[0]) == true)
			moviePage->button_like->setText(QString("Unlike"));
	}

}

void MoviePage::onReturnButtonClick() {

	hide();
	delete moviePage;

}

void MoviePage::onLikeButtonClick()
{
	using namespace sqlite_orm;
	auto movieDB = createMovieStorage("database.db");
    auto userMovieRelationsDB = createUserMovieRelationsDB("database.db");
	auto movieData = movieDB.select(sql::columns(&CSVMovie::m_movieId)
		, sql::where(c(&CSVMovie::m_name) == m_movie.m_name));
	uint32_t movieID = std::get<0>(movieData.at(0));
	auto userMovieRelations = userMovieRelationsDB.select(sql::columns(&Relations::m_user_id, &Relations::m_movie_id, &Relations::m_isWatched,
		&Relations::m_isOnWishlist, &Relations::m_isLiked)
		, sql::where(c(&Relations::m_movie_id) == movieID));

	if (userMovieRelations.size() == 0) {
		Relations r(m_user.GetId(), movieID, false, false, true);
		userMovieRelationsDB.insert(r);
		moviePage->button_like->setText(QString("Unlike"));
	}
	else {
		bool isLiked = true;
		bool watched = std::get<2>(userMovieRelations[0]);
		bool wishlist = std::get<3>(userMovieRelations[0]);
		if (std::get<4>(userMovieRelations[0]) == true) {
			bool fal = false;
			userMovieRelationsDB.update_all(set(c(&Relations::m_user_id) = m_user.GetId(),
				c(&Relations::m_movie_id) = movieID,
				c(&Relations::m_isWatched) = watched,
				c(&Relations::m_isOnWishlist) = wishlist,
				c(&Relations::m_isLiked) = fal), sql::where(c(&Relations::m_movie_id) == movieID));
			moviePage->button_like->setText(QString("Like"));
		}
		else {
			userMovieRelationsDB.update_all(set(c(&Relations::m_user_id) = m_user.GetId(),
				c(&Relations::m_movie_id) = movieID,
				c(&Relations::m_isWatched) = watched,
				c(&Relations::m_isOnWishlist) = wishlist,
				c(&Relations::m_isLiked) = isLiked), sql::where(c(&Relations::m_movie_id) == movieID));
			moviePage->button_like->setText(QString("Unlike"));
		}
	}
}

void MoviePage::onWishlistButtonClick()
{
	using namespace sqlite_orm;

	auto movieDB = createMovieStorage("database.db");
    auto userMovieRelationsDB = createUserMovieRelationsDB("database.db");
	auto movieData = movieDB.select(sql::columns(&CSVMovie::m_movieId)
		, sql::where(c(&CSVMovie::m_name) == m_movie.m_name));
	uint32_t movieID = std::get<0>(movieData.at(0));
	auto userMovieRelations = userMovieRelationsDB.select(sql::columns(&Relations::m_user_id, &Relations::m_movie_id, &Relations::m_isWatched,
		&Relations::m_isOnWishlist, &Relations::m_isLiked)
		, sql::where(c(&Relations::m_movie_id) == movieID));

	if (userMovieRelations.size() == 0) {
		Relations r(m_user.GetId(), movieID, false, true, false);
		userMovieRelationsDB.insert(r);
		moviePage->button_wishlist->setText(QString("Unwish"));
	}
	else {
		bool isLiked = std::get<4>(userMovieRelations[0]);
		bool watched = std::get<2>(userMovieRelations[0]);
		bool wishlist = true;
		if (std::get<3>(userMovieRelations[0]) == true) {
			bool fal = false;
			userMovieRelationsDB.update_all(set(c(&Relations::m_user_id) = m_user.GetId(),
				c(&Relations::m_movie_id) = movieID,
				c(&Relations::m_isWatched) = watched,
				c(&Relations::m_isOnWishlist) = fal,
				c(&Relations::m_isLiked) = isLiked), sql::where(c(&Relations::m_movie_id) == movieID));
			moviePage->button_wishlist->setText(QString("Wishlist"));
		}
		else {
			userMovieRelationsDB.update_all(set(c(&Relations::m_user_id) = m_user.GetId(),
				c(&Relations::m_movie_id) = movieID,
				c(&Relations::m_isWatched) = watched,
				c(&Relations::m_isOnWishlist) = wishlist,
				c(&Relations::m_isLiked) = isLiked), sql::where(c(&Relations::m_movie_id) == movieID));
			moviePage->button_wishlist->setText(QString("Unwish"));
		}
	}

}

void MoviePage::onWatchedButtonClick()
{
	using namespace sqlite_orm;

	auto movieDB = createMovieStorage("database.db");
    auto userMovieRelationsDB = createUserMovieRelationsDB("database.db");
	auto movieData = movieDB.select(sql::columns(&CSVMovie::m_movieId)
		, sql::where(c(&CSVMovie::m_name) == m_movie.m_name));
	uint32_t movieID = std::get<0>(movieData.at(0));
	auto userMovieRelations = userMovieRelationsDB.select(sql::columns(&Relations::m_user_id, &Relations::m_movie_id, &Relations::m_isWatched,
		&Relations::m_isOnWishlist, &Relations::m_isLiked)
		, sql::where(c(&Relations::m_movie_id) == movieID));

	if (userMovieRelations.size() == 0) {
		Relations r(m_user.GetId(), movieID, true, false, false);
		userMovieRelationsDB.insert(r);
		moviePage->button_watched->setText(QString("Unwatch"));
	}
	else {
		bool isLiked = std::get<4>(userMovieRelations[0]);
		bool watched = true;
		bool wishlist = std::get<3>(userMovieRelations[0]);
		if (std::get<2>(userMovieRelations[0]) == true) {
			bool fal = false;
			userMovieRelationsDB.update_all(set(c(&Relations::m_user_id) = m_user.GetId(),
				c(&Relations::m_movie_id) = movieID,
				c(&Relations::m_isWatched) = fal,
				c(&Relations::m_isOnWishlist) = wishlist,
				c(&Relations::m_isLiked) = isLiked), sql::where(c(&Relations::m_movie_id) == movieID));
			moviePage->button_watched->setText(QString("Watched"));
		}
		else {
			userMovieRelationsDB.update_all(set(c(&Relations::m_user_id) = m_user.GetId(),
				c(&Relations::m_movie_id) = movieID,
				c(&Relations::m_isWatched) = watched,
				c(&Relations::m_isOnWishlist) = wishlist,
				c(&Relations::m_isLiked) = isLiked), sql::where(c(&Relations::m_movie_id) == movieID));
			moviePage->button_watched->setText(QString("Unwatch"));
		}
	}
}

void MoviePage::onMovieRecommandationClick(QListWidgetItem* item)
{
	MoviePage* mp = new MoviePage(m_user, GetWholeMovieFromDatabaseByName(moviePage->listWidget->currentItem()->text().toStdString()), this);
	mp->show();
}

MoviePage::~MoviePage()
{
	delete this;
}


