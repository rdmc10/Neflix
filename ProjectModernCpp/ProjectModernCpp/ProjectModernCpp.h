#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjectModernCpp.h"
#include "Register.h"
#include "LoginSuccessful.h"
#include "Database.h"
#include "CSVMovie.h"

class ProjectModernCpp : public QMainWindow
{
    Q_OBJECT

public:
    ProjectModernCpp(QWidget *parent = nullptr);
    ~ProjectModernCpp();

private slots:
    void registerButtonClicked();
    void loginButtonClicked();

private:
    Ui::ProjectModernCppClass *ui;
    database db;
};
