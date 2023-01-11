#pragma once

#include <QMainWindow>
#include "ui_MoviePage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MoviePageClass; };
QT_END_NAMESPACE

class MoviePage : public QMainWindow
{
	Q_OBJECT

public:
	MoviePage(QWidget *parent = nullptr);
	~MoviePage();

private:
	Ui::MoviePageClass *ui;
};
