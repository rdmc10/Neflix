#ifndef USERPREFERENCESWINDOW_H
#define USERPREFERENCESWINDOW_H

#include <QWidget>
#include <unordered_set>
#include "CSVMovie.h"

namespace Ui {
class UserPreferencesWindow;
}

class UserPreferencesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserPreferencesWindow(QWidget *parent = nullptr);
    ~UserPreferencesWindow();

private:
    Ui::UserPreferencesWindow *userPreferences;

    std::unordered_set<std::string> m_movieCategories;

};

#endif // USERPREFERENCESWINDOW_H
