#include "wishlistpage.h"
#include "ui_wishlistpage.h"
WishlistPage::WishlistPage(const User& user, QWidget *parent) :
    m_user(user),
    QWidget(parent),
    ui(new Ui::WishlistPage())
{
    ui->setupUi(this);
	connect(ui->pushButton_close, SIGNAL(clicked()), SLOT(onCloseButtonClick()));

	using namespace sqlite_orm;
	auto movieDB = createMovieStorage("database.db");
    auto userMovieRelationsDB = createUserMovieRelationsDB("database.db");
	auto userMovieRelations = userMovieRelationsDB.select(sql::columns(&Relations::m_user_id, &Relations::m_movie_id, &Relations::m_isWatched,
		&Relations::m_isOnWishlist)
		, sql::where(c(&Relations::m_user_id) == m_user.GetId()));
	
	for (const auto& relation : userMovieRelations) {
		if (std::get<3>(relation)) {
			auto movieData = movieDB.select(sql::columns(&CSVMovie::m_name), sql::where(c(&CSVMovie::m_movieId) == std::get<1>(relation)));
			ui->listWidget_wishlistMovies->addItem(QString::fromStdString(std::get<0>(movieData[0])));
		}
	}
}

void WishlistPage::onCloseButtonClick() {
	hide();
	delete ui;
}

WishlistPage::~WishlistPage()
{
    delete ui;
}
