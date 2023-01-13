#pragma once

#include <QMainWindow>
#include "CSVMovie.h"
#include "ui_MoviePage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MoviePageClass; };
QT_END_NAMESPACE

class MoviePage : public QMainWindow
{
	Q_OBJECT

public:
	MoviePage(CSVMovie movie, QWidget *parent = nullptr);
	~MoviePage();

private slots:

	void onReturnButtonClick();
	void onLikeButtonClick();

private:
	Ui::MoviePageClass *moviePage;
};
