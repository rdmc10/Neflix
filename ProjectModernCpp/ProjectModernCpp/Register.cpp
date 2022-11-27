#include "Register.h"

Register::Register(QWidget *parent)
	: QMainWindow(parent), registerWindow(new Ui::RegisterClass)
{
	registerWindow->setupUi(this);
	connect(registerWindow->buttonCancel, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));
}

Register::~Register()
{
	delete registerWindow;
}

void Register::cancelButtonClicked() 
{
	ProjectModernCpp *mainWindow = new ProjectModernCpp();
	hide();
	// TODO : delete current window
	
	mainWindow->show();
	delete this;
}