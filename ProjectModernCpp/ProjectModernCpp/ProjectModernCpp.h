#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjectModernCpp.h"
#include "Register.h"

class ProjectModernCpp : public QMainWindow
{
    Q_OBJECT

public:
    ProjectModernCpp(QWidget *parent = nullptr);
    ~ProjectModernCpp();

private slots:
    void registerButtonClicked();

private:
    Ui::ProjectModernCppClass *ui;
};
