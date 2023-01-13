#include "ProjectModernCpp.h"
#include "userpreferenceswindow.h"

ProjectModernCpp::ProjectModernCpp(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ProjectModernCppClass)
{
    ui->setupUi(this);
    connect(ui->buttonRegister, SIGNAL(clicked()), this, SLOT(registerButtonClicked()));
    connect(ui->buttonLogin, SIGNAL(clicked()), this, SLOT(loginButtonClicked()));

    if (db.GetMovieCount() == 0) {
        std::vector<std::vector<std::string>> table = db.readCSV("./netflix_titles.csv");
        std::vector<CSVMovie> allMovies;
        for (uint32_t i = 1; i < table.size(); ++i) {
            table[i][0].erase(0, 1);
            CSVMovie tmpMovie(-1, table[i][1], table[i][2], table[i][3], table[i][4], table[i][5], table[i][6], (uint16_t)stoi(table[i][7]), table[i][8], table[i][9]
                , table[i][10], table[i][11]);
            allMovies.push_back(tmpMovie);
        }
        db.PopulateStorage(allMovies);
    }
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
    //UserPreferencesWindow* upw = new UserPreferencesWindow();
    //hide();
    //upw->show();
    registerWindow->show();
}

void ProjectModernCpp::loginButtonClicked()
{   
    
    QString username = ui->inputUsername->text();
    QString password = ui->inputPassword->text();

    User user = getUserFromStorage(username.toStdString());

    if (user.GetPassword() == password.toStdString() && user.GetUsername() == username.toStdString()) {
        LoginSuccessful* loginSuccessful = new LoginSuccessful(user, this);
        hide();
        //MoviePage* moviePage = new MoviePage(GetWholeMovieFromDatabaseByName("The Great British Baking Show"), this);
        //moviePage->show();
        loginSuccessful->show();
    }
    else {
        QMessageBox::warning(this, "Warning!", "Username doesn't exist or password is incorrect!");
    }
}
