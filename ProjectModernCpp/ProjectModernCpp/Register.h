#pragma once

#include <QMainWindow>
#include "ui_Register.h"
#include "ProjectModernCpp.h"

class Register : public QMainWindow
{
	Q_OBJECT

public:
	Register(QWidget *parent = nullptr);
	~Register();

private slots:
	void cancelButtonClicked();

private:
	Ui::RegisterClass *registerWindow;
};
