#include "LoginSuccessful.h"

LoginSuccessful::LoginSuccessful(QWidget* parent)
	: QMainWindow(parent), loggedInPage(new Ui::LoginSuccessfulClass)
{

	loggedInPage->setupUi(this);
}

LoginSuccessful::~LoginSuccessful()
{
	delete loggedInPage;
}
