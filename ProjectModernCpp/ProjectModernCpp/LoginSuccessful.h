#pragma once

#include <QMainWindow>
#include "Database.h"
#include "Movie.h"
#include "User.h"

#include "MoviePage.h"
#include "userpreferenceswindow.h"
#include "ui_LoginSuccessful.h"
#include "wishlistpage.h"

class LoginSuccessful : public QMainWindow
{
	Q_OBJECT

public:
	LoginSuccessful(const User& user, QWidget *parent = nullptr);
	~LoginSuccessful();


private slots:

	// movie click on ListWidget
	void onMovieDoubleClick(QListWidgetItem* item);

	// buttons
	void onUserPreferencesButtonClick();

	// search bar
	void onSearchBarChange(const QString& string);

	void onWishlistButtonClick();

private:
	Ui::LoginSuccessfulClass *mainPage;

	User m_user;
};
