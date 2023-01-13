#include "LoginSuccessful.h"

LoginSuccessful::LoginSuccessful(const User& user, QWidget* parent)
	: QMainWindow(parent), mainPage(new Ui::LoginSuccessfulClass), m_user(user)
{
	
	mainPage->setupUi(this);
	connect(mainPage->listWidget_movies, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onMovieDoubleClick(QListWidgetItem*)));

	connect(mainPage->pushButton_preferences, SIGNAL(clicked()), SLOT(onUserPreferencesButtonClick()));

	connect(mainPage->lineEdit_searchMovie, SIGNAL(textChanged(const QString&)), this, SLOT(onSearchBarChange(const QString&)));


	mainPage->label_username->setText(QString::fromStdString("Username: " + user.GetUsername() + " " + std::to_string(user.GetId())));


	

}

void LoginSuccessful::onMovieDoubleClick(QListWidgetItem* item) {

	MoviePage* moviePage = new MoviePage(GetWholeMovieFromDatabaseByName(mainPage->listWidget_movies->currentItem()->text().toStdString()), this);
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

LoginSuccessful::~LoginSuccessful()
{
	delete mainPage;
}
