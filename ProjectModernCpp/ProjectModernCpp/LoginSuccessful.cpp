#include "LoginSuccessful.h"

LoginSuccessful::LoginSuccessful(QWidget* parent)
	: QMainWindow(parent), loggedInPage(new Ui::LoginSuccessfulClass)
{
	loggedInPage->setupUi(this);
	Movie::PopulateMovies("netflix_titles.csv");
}

LoginSuccessful::~LoginSuccessful()
{
	delete loggedInPage;
}
