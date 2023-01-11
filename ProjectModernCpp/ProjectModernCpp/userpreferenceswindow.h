#ifndef USERPREFERENCESWINDOW_H
#define USERPREFERENCESWINDOW_H

#include <QWidget>
#include <unordered_set>
#include <vector>
#include "CSVMovie.h"
#include <QListWidget>



namespace Ui {
class UserPreferencesWindow;
}

class UserPreferencesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserPreferencesWindow(QWidget *parent = nullptr);

    ~UserPreferencesWindow();

private slots:
    void onCategoriesWidgetDoubleClick(QListWidgetItem* item);
    void onSelectedCategoriesWidgetDoubleClick(QListWidgetItem* item);
    void onRatingsWidgetDoubleClick(QListWidgetItem* item);
    void onSelectedRatingsWidgetDoubleClick(QListWidgetItem* item);
    void onMoviesWidgetDoubleClick(QListWidgetItem* item);
    void onSelectedMoviesWidgetDoubleClick(QListWidgetItem* item);

    void onSaveButtonClick();

    void onSearchBarEdit(const QString& string);

private:
    Ui::UserPreferencesWindow *userPreferences;
    


    std::unordered_set<std::string> m_movieCategories;
    std::unordered_set<std::string> m_movieRatings;
    std::unordered_set<std::string> m_movies;

};

#endif // USERPREFERENCESWINDOW_H
