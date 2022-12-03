#include "ProjectModernCpp.h"
#include <iostream>

ProjectModernCpp::ProjectModernCpp(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ProjectModernCppClass)
{
    ui->setupUi(this);
    connect(ui->buttonRegister, SIGNAL(clicked()), this, SLOT(registerButtonClicked()));
    std::cout << "ok";
}

ProjectModernCpp::~ProjectModernCpp()
{
    delete ui;
}

void ProjectModernCpp::registerButtonClicked()
{
    Register *registerWindow = new Register();
    hide();
    // TODO : free memory for current window
    registerWindow->show();
}
