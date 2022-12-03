#include "ProjectModernCpp.h"

ProjectModernCpp::ProjectModernCpp(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ProjectModernCppClass)
{
    ui->setupUi(this);
    connect(ui->buttonRegister, SIGNAL(clicked()), this, SLOT(registerButtonClicked()));
    connect(ui->buttonLogin, SIGNAL(clicked()), this, SLOT(loginButtonClicked()));
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

void ProjectModernCpp::loginButtonClicked()
{   
    // TODO : check if credentials are valid

    LoginSuccessful* loginSuccessful = new LoginSuccessful(this);
    hide();
    loginSuccessful->show();
}
