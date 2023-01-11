#include "userpreferenceswindow.h"
#include "ui_userpreferenceswindow.h"


UserPreferencesWindow::UserPreferencesWindow(QWidget *parent) :
    QWidget(parent),
    userPreferences(new Ui::UserPreferencesWindow)

{
    userPreferences->setupUi(this);
    connect(userPreferences->listWidget_movieCategories, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onCategoriesWidgetDoubleClick(QListWidgetItem*)));
    connect(userPreferences->listWidget_selectedMovieCategories, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onSelectedCategoriesWidgetDoubleClick(QListWidgetItem*)));

    connect(userPreferences->listWidget_movieRatings, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onRatingsWidgetDoubleClick(QListWidgetItem*)));
    connect(userPreferences->listWidget_selectedMovieRatings, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onSelectedRatingsWidgetDoubleClick(QListWidgetItem*)));

    connect(userPreferences->listWidget_movies, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onMoviesWidgetDoubleClick(QListWidgetItem*)));
    connect(userPreferences->listWidget_selectedMovies, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onSelectedMoviesWidgetDoubleClick(QListWidgetItem*)));

    connect(userPreferences->saveButton, SIGNAL(clicked()), this, SLOT(onSaveButtonClick()));

    connect(userPreferences->lineEdit_movieSearch, SIGNAL(textChanged(const QString&)), this, SLOT(onSearchBarEdit(const QString&)));

    m_movieCategories = GetCategoriesFromDatabase();
    m_movieRatings = GetRatingsFromDatabase();
 

    for (const auto& category : m_movieCategories) {

        userPreferences->listWidget_movieCategories->addItem(QString::fromStdString(category));
        
    }

    for (const auto& rating : m_movieRatings) {

        userPreferences->listWidget_movieRatings->addItem(QString::fromStdString(rating));

    }
  
}

void UserPreferencesWindow::onCategoriesWidgetDoubleClick(QListWidgetItem* item)
{

    userPreferences->listWidget_movieCategories->takeItem(userPreferences->listWidget_movieCategories->row(item));
    userPreferences->listWidget_selectedMovieCategories->addItem(item);
}

void UserPreferencesWindow::onSelectedCategoriesWidgetDoubleClick(QListWidgetItem* item)
{
    userPreferences->listWidget_selectedMovieCategories->takeItem(userPreferences->listWidget_selectedMovieCategories->row(item));
    userPreferences->listWidget_movieCategories->addItem(item);
}

void UserPreferencesWindow::onRatingsWidgetDoubleClick(QListWidgetItem* item)
{

    userPreferences->listWidget_movieRatings->takeItem(userPreferences->listWidget_movieRatings->row(item));
    userPreferences->listWidget_selectedMovieRatings->addItem(item);
}

void UserPreferencesWindow::onSelectedRatingsWidgetDoubleClick(QListWidgetItem* item)
{
    userPreferences->listWidget_selectedMovieRatings->takeItem(userPreferences->listWidget_selectedMovieRatings->row(item));
    userPreferences->listWidget_movieRatings->addItem(item);
   
}

void UserPreferencesWindow::onMoviesWidgetDoubleClick(QListWidgetItem* item)
{

    userPreferences->listWidget_movies->takeItem(userPreferences->listWidget_movies->row(item));
    userPreferences->listWidget_selectedMovies->addItem(item);
}

void UserPreferencesWindow::onSelectedMoviesWidgetDoubleClick(QListWidgetItem* item)
{
    userPreferences->listWidget_selectedMovies->takeItem(userPreferences->listWidget_selectedMovies->row(item));

}

void UserPreferencesWindow::onSaveButtonClick()
{

    std::vector<std::string> likedCategories;
    std::vector<std::string> likedRatings;
    std::vector<std::string> likedMovies;
    std::string likedType; //Movie, TV_Show, Both

    for (int i = 0; i < userPreferences->listWidget_selectedMovieCategories->count(); i++) {

        likedCategories.push_back(userPreferences->listWidget_selectedMovieCategories->item(i)->text().toStdString());

    }

    for (int i = 0; i < userPreferences->listWidget_selectedMovieRatings->count(); i++) {

        likedRatings.push_back(userPreferences->listWidget_selectedMovieRatings->item(i)->text().toStdString());

    }

    for (int i = 0; i < userPreferences->listWidget_selectedMovies->count(); i++) {

        likedMovies.push_back(userPreferences->listWidget_selectedMovies->item(i)->text().toStdString());

    }

    if (userPreferences->checkBox_Movie->isChecked() && userPreferences->checkBox_TVShow->isChecked())
        likedType = "Both";
    else if (userPreferences->checkBox_TVShow->isChecked())
        likedType = "TV_Show";
    else likedType = "Movie"; // if no_checkbox/movie checkbox is checked

    userPreferences->listWidget_selectedMovieCategories->clear();
    userPreferences->listWidget_selectedMovieRatings->clear();
    userPreferences->listWidget_selectedMovies->clear();

    // TODO: Insert saved data (likedCategories, likedRatings, likedMovies, likedType) into the database for user preferences


}

void UserPreferencesWindow::onSearchBarEdit(const QString& string)
{
    if (string.size() > 1) { // must be higher than 1 so it doesnt load all 8000+ movies
        m_movies = GetCertainMoviesFromDatabase(userPreferences->lineEdit_movieSearch->text().toStdString());

        userPreferences->listWidget_movies->clear();

        for (auto movie : m_movies) {

            userPreferences->listWidget_movies->addItem(QString::fromStdString(movie));

        }
    }
    
}


UserPreferencesWindow::~UserPreferencesWindow()
{
    delete userPreferences;
}

