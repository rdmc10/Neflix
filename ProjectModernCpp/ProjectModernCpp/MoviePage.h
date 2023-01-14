#pragma once

#include <QMainWindow>
#include "CSVMovie.h"
#include "ui_MoviePage.h"
#include <string>
#include "User.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MoviePageClass; };
QT_END_NAMESPACE

namespace sql = sqlite_orm;

class MoviePage : public QMainWindow
{
	Q_OBJECT

public:
	MoviePage(const User& user, CSVMovie movie, QWidget *parent = nullptr);
	~MoviePage();

private slots:

	void onReturnButtonClick();
	void onLikeButtonClick();
	void onWishlistButtonClick();
	void onWatchedButtonClick();

private:
	Ui::MoviePageClass *moviePage;
	User m_user;
	CSVMovie m_movie;
};

struct Relations {

	uint32_t m_user_id;
	uint32_t m_movie_id;
	bool m_isWatched;
	bool m_isOnWishlist;
	bool m_isLiked;


	Relations() {
		m_user_id = -1;
		m_movie_id = -1;
		m_isWatched = 0;
		m_isOnWishlist = 0;
		m_isLiked = 0;
	}

	Relations(uint32_t user_id, uint32_t movie_id, bool isWatched = 0, bool isOnWishList = 0, bool isLiked = 0) :
		m_user_id(user_id),
		m_movie_id(movie_id),
		m_isWatched(isWatched),
		m_isOnWishlist(isOnWishList),
		m_isLiked(isLiked)
	{}

};

inline auto createUserMovieRelationsDB(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"user_movie_relations",
			sql::make_column("user_id", &Relations::m_user_id),
			sql::make_column("movie_id", &Relations::m_movie_id),
			sql::make_column("is_watched", &Relations::m_isWatched),
			sql::make_column("is_on_wishlist", &Relations::m_isOnWishlist),
			sql::make_column("is_liked", &Relations::m_isLiked)
		)
	);
}

using UserMovieDatabase = decltype(createUserMovieRelationsDB(""));
