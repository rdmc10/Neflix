#include "userpreferenceswindow.h"
#include "ui_userpreferenceswindow.h"
#include "MoviePage.h"

UserPreferencesWindow::UserPreferencesWindow(const User& user, QWidget *parent) :
    QWidget(parent),
    userPreferences(new Ui::UserPreferencesWindow),
    m_user(user)

{
    qDebug() << m_user.GetId();
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
 
    auto userPrefDB = createUserPreferencesStorage("database.db");
    Preferences userPref(m_user.GetId(), "", "", "", "");

    if (!checkIfUserPreferencesExist(m_user.GetId())) {
        userPrefDB.insert(userPref);
      
    }
    using namespace sqlite_orm;
    auto userPrefData = userPrefDB.select(sql::columns(&Preferences::m_user_id, &Preferences::m_preferencesMoviesLiked, &Preferences::m_preferencesRatingsLiked, &Preferences::m_preferencesCategoriesLiked, &Preferences::m_preferencesTypeLiked)
        , sql::where(c(&Preferences::m_user_id) == m_user.GetId()));

    userPref.m_preferencesMoviesLiked = std::get<1>(userPrefData.at(0));
    userPref.m_preferencesRatingsLiked = std::get<2>(userPrefData.at(0));
    userPref.m_preferencesCategoriesLiked = std::get<3>(userPrefData.at(0));
    userPref.m_preferencesTypeLiked = std::get<4>(userPrefData.at(0));
    

    std::vector<std::string> likedCategories = SplitString(userPref.m_preferencesCategoriesLiked, ",");
    std::vector<std::string> likedRatings = SplitString(userPref.m_preferencesRatingsLiked, ",");
    std::vector<std::string> likedMovies = SplitString(userPref.m_preferencesMoviesLiked, ",");
    std::string likedType = userPref.m_preferencesTypeLiked; //Movie, TV_Show, Both

    for (int i = 0; i<likedCategories.size(); i++)
        if (likedCategories[i] != "")
            userPreferences->listWidget_selectedMovieCategories->addItem(QString::fromStdString(likedCategories[i]));
    for (int i = 0; i < likedRatings.size(); i++)
        if (likedRatings[i] != "")
            userPreferences->listWidget_selectedMovieRatings->addItem(QString::fromStdString(likedRatings[i]));
    for (int i = 0; i < likedMovies.size(); i++)
        if (likedMovies[i] != "")
            userPreferences->listWidget_selectedMovies->addItem(QString::fromStdString(likedMovies[i]));

    if (likedType == "Both") {
        userPreferences->checkBox_Movie->setChecked(true);
        userPreferences->checkBox_TVShow->setChecked(true);
    } else if (likedType == "Movie")
        userPreferences->checkBox_Movie->setChecked(true);
    else 
        userPreferences->checkBox_TVShow->setChecked(true);

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
    //MoviePage* moviePage = new MoviePage(GetWholeMovieFromDatabaseByName(userPreferences->listWidget_selectedMovies->currentItem()->text().toStdString()), this);
    //moviePage->show();
}

void UserPreferencesWindow::onSaveButtonClick()
{

    std::vector<std::string> likedCategories;
    std::vector<std::string> likedRatings;
    std::vector<std::string> likedMovies;
    std::string likedType; //Movie, TV_Show, Both

    std::string categories = "";
    std::string ratings = "";
    std::string movies = "";


    for (int i = 0; i < userPreferences->listWidget_selectedMovieCategories->count(); i++) {

        likedCategories.push_back(userPreferences->listWidget_selectedMovieCategories->item(i)->text().toStdString());
        categories += likedCategories[i] + ",";
    }

    for (int i = 0; i < userPreferences->listWidget_selectedMovieRatings->count(); i++) {

        likedRatings.push_back(userPreferences->listWidget_selectedMovieRatings->item(i)->text().toStdString());
        ratings += likedRatings[i] + ",";
    }

    for (int i = 0; i < userPreferences->listWidget_selectedMovies->count(); i++) {

        likedMovies.push_back(userPreferences->listWidget_selectedMovies->item(i)->text().toStdString());
        movies += likedMovies[i] + ",";
    }

    if (userPreferences->checkBox_Movie->isChecked() && userPreferences->checkBox_TVShow->isChecked())
        likedType = "Both";
    else if (userPreferences->checkBox_TVShow->isChecked())
        likedType = "TV_Show";
    else likedType = "Movie"; // if no_checkbox/movie checkbox is checked


    Preferences pref(m_user.GetId(), movies, ratings, categories, likedType);
    auto userPrefDB = createUserPreferencesStorage("database.db");

    using namespace sqlite_orm;

    userPrefDB.update_all(set(c(&Preferences::m_user_id) = m_user.GetId(),
        c(&Preferences::m_preferencesMoviesLiked) = movies,
        c(&Preferences::m_preferencesRatingsLiked) = ratings,
        c(&Preferences::m_preferencesCategoriesLiked) = categories,
        c(&Preferences::m_preferencesTypeLiked) = likedType), sql::where(c(&Preferences::m_user_id) == m_user.GetId()));

  


    userPreferences->listWidget_selectedMovieCategories->clear();
    userPreferences->listWidget_selectedMovieRatings->clear();
    userPreferences->listWidget_selectedMovies->clear();

    // TODO: Insert saved data (likedCategories, likedRatings, likedMovies, likedType) into the database for user preferences

    hide();
    delete userPreferences;

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

