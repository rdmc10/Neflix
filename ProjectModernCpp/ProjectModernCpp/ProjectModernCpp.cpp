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
    
    QString username = ui->inputUsername->text();
    QString password = ui->inputPassword->text();

    User user = getUserFromStorage(username.toStdString());

    if (user.GetPassword() == password.toStdString() && user.GetUsername() == username.toStdString()) {
        LoginSuccessful* loginSuccessful = new LoginSuccessful(this);
        hide();
        loginSuccessful->show();
    }
    else {
        QMessageBox::warning(this, "Warning!", "Username doesn't exist or password is incorrect!");
    }
}
