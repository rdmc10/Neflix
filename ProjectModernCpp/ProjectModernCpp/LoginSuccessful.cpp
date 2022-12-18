#include "LoginSuccessful.h"
#include "CSVMovie.h"

LoginSuccessful::LoginSuccessful(QWidget* parent)
	: QMainWindow(parent), loggedInPage(new Ui::LoginSuccessfulClass)
{

	loggedInPage->setupUi(this);
	std::vector<std::vector<std::string>> table = db.readCSV("./netflix_titles.csv");
	std::vector<CSVMovie> allMovies;
	for (uint32_t i = 0; i < table.size()-2; ++i) {
		if (i == 0)continue;
		table[i][0].erase(0, 1);
		CSVMovie tmpMovie(-1,table[i][1],table[i][2],table[i][3],table[i][4],table[i][5],table[i][6],(uint16_t)stoi(table[i][7]),table[i][8],table[i][9]
		,table[i][10],table[i][11]);
		allMovies.push_back(tmpMovie);

	}

	//db.PopulateStorage(allMovies);
	//qDebug() << db.GetMovieCount();
}

LoginSuccessful::~LoginSuccessful()
{
	delete loggedInPage;
}
