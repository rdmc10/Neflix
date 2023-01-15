#include "LoginSuccessful.h"
#include "recommandationwindow.h"

LoginSuccessful::LoginSuccessful(const User& user, QWidget* parent)
	: QMainWindow(parent), mainPage(new Ui::LoginSuccessfulClass), m_user(user)
{
	
	mainPage->setupUi(this);
	connect(mainPage->listWidget_movies, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onMovieDoubleClick(QListWidgetItem*)));

	connect(mainPage->pushButton_preferences, SIGNAL(clicked()), SLOT(onUserPreferencesButtonClick()));

	connect(mainPage->lineEdit_searchMovie, SIGNAL(textChanged(const QString&)), this, SLOT(onSearchBarChange(const QString&)));

	connect(mainPage->pushButton_wishlist, SIGNAL(clicked()), SLOT(onWishlistButtonClick()));

	connect(mainPage->pushButton_recommandations, SIGNAL(clicked()), SLOT(onRecommandationClick()));


	mainPage->label_username->setText(QString::fromStdString("Username: " + user.GetUsername()));


	

}

void LoginSuccessful::onMovieDoubleClick(QListWidgetItem* item) {

	MoviePage* moviePage = new MoviePage(m_user,GetWholeMovieFromDatabaseByName(mainPage->listWidget_movies->currentItem()->text().toStdString()), this);
	moviePage->show();


}

void LoginSuccessful::onUserPreferencesButtonClick()
{

	UserPreferencesWindow* upw = new UserPreferencesWindow(m_user);
	upw->show();


}

void LoginSuccessful::onSearchBarChange(const QString& string)
{
        std::unordered_set<std::string> m_movies = GetCertainMoviesFromDatabase(mainPage->lineEdit_searchMovie->text().toStdString());

        mainPage->listWidget_movies->clear();

        for (auto movie : m_movies) {

            mainPage->listWidget_movies->addItem(QString::fromStdString(movie));

        }

}

void LoginSuccessful::onWishlistButtonClick()
{
	WishlistPage* wp = new WishlistPage(this->m_user);
	wp->show();

}

void LoginSuccessful::onRecommandationClick()
{
	RecommandationWindow* rw = new RecommandationWindow(this->m_user);
	rw->show();

}

LoginSuccessful::~LoginSuccessful()
{
	delete mainPage;
}
