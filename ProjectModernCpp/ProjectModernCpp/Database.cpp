#include "Database.h"
#include "ParseUtil.h"
#include <qmainwindow.h>
#include <string>

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

std::vector<Movie> database::GetMoviesData()
{
    auto csvmovies = m_db.get_all<CSVMovie>();
    std::vector<Movie> moviesData;
    for (const auto& csvmovie : csvmovies) {
        Movie tmp (
            csvmovie.m_movieId
            , csvmovie.m_type == "Movie" ? Movie::Type::Movie : Movie::Type::Show
            , csvmovie.m_name
            , ParseString(csvmovie.m_directors)
            , ParseString(csvmovie.m_cast)
            , csvmovie.m_country
            , csvmovie.m_dateAdded
            , csvmovie.m_releaseDate
            , csvmovie.m_rating
            , csvmovie.m_duration
            , ParseString(csvmovie.m_categories)
            , csvmovie.m_description
        );

        moviesData.push_back(tmp);
    }
    return moviesData;
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
