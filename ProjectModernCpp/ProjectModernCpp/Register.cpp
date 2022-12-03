#include "Register.h"
#include <iostream>
#include <string>

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
	userStorage.sync_schema();

	auto id = userStorage.insert(user);
	user.SetId(id);

	QMessageBox::information(this, "Registered", "Account created successfully!");
	cancelButtonClicked();
}

void Register::cancelButtonClicked() 
{
	ProjectModernCpp *mainWindow = new ProjectModernCpp();
	hide();
	// TODO : delete current window
	
	mainWindow->show();
	delete this;
}