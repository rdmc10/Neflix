#include "userpreferenceswindow.h"
#include "ui_userpreferenceswindow.h"

UserPreferencesWindow::UserPreferencesWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPreferencesWindow)
{
    ui->setupUi(this);
}

UserPreferencesWindow::~UserPreferencesWindow()
{
    delete ui;
}
