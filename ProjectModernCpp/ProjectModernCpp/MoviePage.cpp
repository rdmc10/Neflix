#include "MoviePage.h"

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
	

}

void MoviePage::onReturnButtonClick() {

	delete this;

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
		Relations r(m_user.GetId(), movieID, true, false, true);
		userMovieRelationsDB.insert(r);
	}
	else {
		bool isLiked = true;
		bool fal = false;
		userMovieRelationsDB.update_all(set(c(&Relations::m_user_id) = m_user.GetId(),
			c(&Relations::m_movie_id) = movieID,
			c(&Relations::m_isWatched) = fal,
			c(&Relations::m_isOnWishlist) = fal,
			c(&Relations::m_isLiked) = isLiked), sql::where(c(&Relations::m_movie_id) == movieID));
	}

}

MoviePage::~MoviePage()
{
	delete moviePage;
}


