#include "MoviePage.h"

MoviePage::MoviePage(CSVMovie movie, QWidget *parent)
	: QMainWindow(parent)
	, moviePage(new Ui::MoviePageClass())
{
	moviePage->setupUi(this);

	moviePage->label_movieName->setText(QString::fromStdString(movie.m_name + " ( " + movie.m_type + " - " + std::to_string(movie.m_releaseDate) + " )"));
	moviePage->label_movieName->setAlignment(Qt::AlignCenter);

	moviePage->label_movieRating->setText(moviePage->label_movieRating->text() + " " + QString::fromStdString(movie.m_rating));

	moviePage->textBrowser_movieDescription->setText(QString::fromStdString(movie.m_description));

	std::vector<std::string> categories = SplitString(movie.m_categories, ",");
	for (auto cat : categories) {
		if (std::isspace(cat[0]))
			cat.erase(0, 1);
		moviePage->listWidget_movieCategories->addItem(QString::fromStdString(cat));
	}
	
	std::vector<std::string> cast = SplitString(movie.m_cast, ",");
	for (auto member : cast) {
		if (std::isspace(member[0]))
			member.erase(0, 1);
		moviePage->listWidget_movieCast->addItem(QString::fromStdString(member));
	}

	std::vector<std::string> directors = SplitString(movie.m_directors, ",");
	for (auto director : directors) {
		if (std::isspace(director[0]))
			director.erase(0, 1);
		moviePage->listWidget_movieDirectors->addItem(QString::fromStdString(director));
	}

	std::vector<std::string> countries = SplitString(movie.m_country, ",");
	for (auto country : countries) {
		if (std::isspace(country[0]))
			country.erase(0, 1);
		moviePage->listWidget_movieCountries->addItem(QString::fromStdString(country));
	}
	

}

MoviePage::~MoviePage()
{
	delete moviePage;
}
