#include "Database.h"
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

std::vector<Movie> database::GetMoviesData()
{
    auto results = m_db.select(&CSVMovie::m_movieId, &CSVMovie::m_type, &CSVMovie::m_name, &CSVMovie::m_directors, &CSVMovie::m_cast, &CSVMovie::m_country, &CSVMovie::m_dateAdded, &CSVMovie::m_releaseDate, &CSVMovie::m_rating, &CSVMovie::m_duration, &CSVMovie::m_categories, &CSVMovie::m_description);
    std::vector<Movie> moviesData;
    for (const auto& row : results) {
        // TODO : process database data and convert to std::vector<Movie>
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
