#include "recommandationwindow.h"
#include "ui_recommandationwindow.h"



RecommandationWindow::RecommandationWindow(const User& user, QWidget *parent) :
    QWidget(parent),
    m_user(user),
    ui(new Ui::RecommandationWindow)
{
    ui->setupUi(this);

	database db;
	connect(ui->listWidget_recommandations, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onMovieDoubleClick(QListWidgetItem*)));
    connect(ui->pushButton_return, SIGNAL(clicked()), SLOT(onReturnClick()));

    using namespace sqlite_orm;
	auto movieDB = createMovieStorage("database.db");
	auto userMovieRelationsDB = createUserMovieRelationsDB("database.db");
	auto userMovieRelations = userMovieRelationsDB.select(sql::columns(&Relations::m_user_id, &Relations::m_movie_id, &Relations::m_isLiked,
		&Relations::m_isOnWishlist)
		, sql::where(c(&Relations::m_user_id) == m_user.GetId()));

	for (const auto& relation : userMovieRelations) {
		if (std::get<2>(relation)) {
			auto movieData = movieDB.select(sql::columns(&CSVMovie::m_name), sql::where(c(&CSVMovie::m_movieId) == std::get<1>(relation)));

			auto moviesFromDb = movieDB.select(sql::columns(&CSVMovie::m_movieId, &CSVMovie::m_type, &CSVMovie::m_name, &CSVMovie::m_directors, &CSVMovie::m_cast, &CSVMovie::m_country,
				&CSVMovie::m_dateAdded, &CSVMovie::m_releaseDate, &CSVMovie::m_rating, &CSVMovie::m_duration, &CSVMovie::m_categories, &CSVMovie::m_description), sql::where(sql::like(&CSVMovie::m_name, std::get<0>(movieData[0]))));
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

			srand(std::time(NULL));
            std::vector<Movie> movies = CosineSimilarity::GetSimilarMovies(tmp, db.GetMoviesData());
            for (uint32_t i = 0; i < 5 % movies.size(); ++i) {
                ui->listWidget_recommandations->addItem(QString::fromStdString(movies[rand() % movies.size()].GetName()));
            }
		}
	}
}

void RecommandationWindow::onMovieDoubleClick(QListWidgetItem* item) {

	MoviePage* mp = new MoviePage(m_user, GetWholeMovieFromDatabaseByName(ui->listWidget_recommandations->currentItem()->text().toStdString()), this);
	mp->show();

}

void RecommandationWindow::onReturnClick() {
    hide();
    delete ui;
}

RecommandationWindow::~RecommandationWindow()
{
    delete this;
}
