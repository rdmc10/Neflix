#include "userpreferenceswindow.h"
#include "ui_userpreferenceswindow.h"


UserPreferencesWindow::UserPreferencesWindow(QWidget *parent) :
    QWidget(parent),
    userPreferences(new Ui::UserPreferencesWindow)
{
    userPreferences->setupUi(this);

    m_movieCategories = GetCategoriesFromDatabase();
 

    for (const auto& category : m_movieCategories) {

        userPreferences->listWidget_movieCategories->addItem(QString::fromStdString(category));

    }

    QListWidgetItem *item = new QListWidgetItem("da");
    userPreferences->listWidget_movieCategories->addItem(item);
    //userPreferences->listWidget_movieCategories->takeItem(m_movieCategories.size());
    userPreferences->listWidget_movieCategories->takeItem(userPreferences->listWidget_movieCategories->row(item));
}

UserPreferencesWindow::~UserPreferencesWindow()
{
    delete userPreferences;
}
