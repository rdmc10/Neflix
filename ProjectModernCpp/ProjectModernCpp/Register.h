#pragma once

#include <QMessageBox>
#include "User.h"
#include "Movie.h"
#include <QMainWindow>
#include "ui_Register.h"
#include "ProjectModernCpp.h"
#include "UserPreferences.h"

class Register : public QMainWindow
{
	Q_OBJECT

public:
	Register(QWidget *parent = nullptr);
	~Register();

private:
	bool validEmail(const std::string& email);
	User GetRegisterData();

private slots:
	void cancelButtonClicked();
	void registerButtonClicked();

private:
	Ui::RegisterClass *registerWindow;
};
