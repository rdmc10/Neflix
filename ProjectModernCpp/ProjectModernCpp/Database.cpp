#include "Database.h"
#include "ParseUtil.h"
#include <qmainwindow.h>

enum class CSVState {
    UnquotedField,
    QuotedField,
    QuotedQuote
};

std::vector<std::string> database::readCSVRow(const std::string& row) {
    CSVState state = CSVState::UnquotedField;
    std::vector<std::string> fields{ "" };
    size_t i = 0; 
    for (char c : row) {
        switch (state) {
        case CSVState::UnquotedField:
            switch (c) {
            case ',': 
                fields.push_back(""); i++;
                break;
            case '"': state = CSVState::QuotedField;
                break;
            default:  fields[i].push_back(c);
                break;
            }
            break;
        case CSVState::QuotedField:
            switch (c) {
            case '"': state = CSVState::QuotedQuote;
                break;
            default:  fields[i].push_back(c);
                break;
            }
            break;
        case CSVState::QuotedQuote:
            switch (c) {
            case ',': 
                fields.push_back(""); i++;
                state = CSVState::UnquotedField;
                break;
            case '"': 
                fields[i].push_back('"');
                state = CSVState::QuotedField;
                break;
            default:  
                state = CSVState::UnquotedField;
                break;
            }
            break;
        }
    }
    return fields;
}

void database::PopulateStorage(std::vector<CSVMovie> movies)
{
    for (auto& movie : movies) {
        auto id = m_db.insert(movie);
        movie.m_movieId = id;
    }
}

void database::GetMoviesData()
{
    auto csvmovies = m_db.get_all<CSVMovie>();
    std::vector<Movie> moviesData;
    for (const auto& csvmovie : csvmovies) {
        Movie tmp;
        tmp.SetID(csvmovie.m_movieId);
        tmp.SetType(csvmovie.m_type == "Movie" ? Movie::Type::Movie : Movie::Type::Show);
        tmp.SetName(csvmovie.m_name);
        tmp.SetDirectors(ParseString(csvmovie.m_directors));
        tmp.SetCast(ParseString(csvmovie.m_cast));
        tmp.SetCountry(csvmovie.m_country);
        tmp.SetDateAdded(csvmovie.m_dateAdded);
        tmp.SetReleaseDate(csvmovie.m_releaseDate);
        tmp.SetRating(csvmovie.m_rating);
        // tmp.SetDuration(csvmovie.m_duration);
    }

}

int database::GetMovieCount()
{
    auto movieCount = m_db.count<CSVMovie>();
    return movieCount;
}

std::vector<std::vector<std::string>> database::readCSV(const std::string& csvPath) {
    std::ifstream in(csvPath);
    std::vector<std::vector<std::string>> table;
    std::string row;
    while (!in.eof()) {
        std::getline(in, row);
        if (in.bad() || in.fail()) {
            break;
        }
        auto fields = readCSVRow(row);
        table.push_back(fields);
    }
    return table;
}
