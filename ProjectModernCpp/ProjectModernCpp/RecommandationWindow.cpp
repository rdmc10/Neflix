#include "RecommandationWindow.h"

RecommandationWindow::RecommandationWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::RecommandationWindowClass())
{
	ui->setupUi(this);
}

RecommandationWindow::~RecommandationWindow()
{
	delete ui;
}
