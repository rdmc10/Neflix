#include "Register.h"
#include <iostream>
#include <string>
#include "Movie.h"
#include "userpreferenceswindow.h"
#include <regex>

Register::Register(QWidget *parent)
	: QMainWindow(parent), registerWindow(new Ui::RegisterClass)
{
	registerWindow->setupUi(this);
	connect(registerWindow->buttonCancel, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));
	connect(registerWindow->buttonRegister, SIGNAL(clicked()), this, SLOT(registerButtonClicked()));
}

Register::~Register()
{
	delete registerWindow;
}

bool Register::validEmail(const std::string& email)
{
	const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return regex_match(email, pattern);
}

User Register::GetRegisterData()
{
	User user;

	user.SetUsername(registerWindow->fieldUsername->text().toStdString());
	user.SetFirstName(registerWindow->fieldFirstName->text().toStdString());
	user.SetLastName(registerWindow->fieldLastName->text().toStdString());
	user.SetEmail(registerWindow->fieldEmail->text().toStdString());
	user.SetBirthDate(registerWindow->fieldBirthdate->text().toStdString());

	if (registerWindow->fieldPassword->text() == registerWindow->fieldConfirmPassword->text())
		user.SetPassword(registerWindow->fieldPassword->text().toStdString());
	else
		QMessageBox::warning(this, "Warning!", "Passwords don't match");
		

	return user;
}

void Register::registerButtonClicked()
{
	User user = GetRegisterData();
	auto userStorage = createStorage("database.db");
	auto userPreferencesStorage = createUserPreferencesStorage("database.db");
	userStorage.sync_schema();
	User userFromDatabase = getUserFromStorage(user.GetUsername());

	bool newUser = false;
	if (userFromDatabase.GetUsername() != user.GetUsername() && userFromDatabase.GetEmail() != user.GetEmail()) {
			newUser = true;
	}

	if (!validEmail(registerWindow->fieldEmail->text().toStdString())) {
		QMessageBox::warning(this, "Warning", "Invalid email!");
		registerWindow->fieldEmail->clear();
		return;
	}

	if (newUser) {
		auto id = userStorage.insert(user);

		Preferences pref(id, "", "", "", "");
		userPreferencesStorage.insert(pref);
		user.SetId(id);
		QMessageBox::information(this, "Registered", "Account created successfully!");
		UserPreferencesWindow* upw = new UserPreferencesWindow(user);
		LoginSuccessful* mainPage = new LoginSuccessful(user);
		hide();
		delete registerWindow;
		mainPage->show();
		upw->show();
	}
	else {
		QMessageBox::warning(this, "Warning", "An account with this username or email already exists!");
		registerWindow->fieldUsername->clear();
	}

}

void Register::cancelButtonClicked() 
{
	ProjectModernCpp *mainWindow = new ProjectModernCpp();
	hide();
	
	mainWindow->show();
	delete this;
}