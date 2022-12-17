#include "LoginSuccessful.h"
#include "Database.h"

LoginSuccessful::LoginSuccessful(QWidget* parent)
	: QMainWindow(parent), loggedInPage(new Ui::LoginSuccessfulClass)
{
	loggedInPage->setupUi(this);
	database::readCSV("./netflix_titles.csv");

}

LoginSuccessful::~LoginSuccessful()
{
	delete loggedInPage;
}
