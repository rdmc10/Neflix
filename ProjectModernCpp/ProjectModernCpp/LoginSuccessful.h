#pragma once

#include <QMainWindow>
#include "ui_LoginSuccessful.h"

class LoginSuccessful : public QMainWindow
{
	Q_OBJECT

public:
	LoginSuccessful(QWidget *parent = nullptr);
	~LoginSuccessful();

private:
	Ui::LoginSuccessfulClass *loggedInPage;
};
