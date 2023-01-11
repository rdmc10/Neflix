#include "MoviePage.h"

MoviePage::MoviePage(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MoviePageClass())
{
	ui->setupUi(this);
}

MoviePage::~MoviePage()
{
	delete ui;
}
