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
    m_db.insert_range(movies.begin(), movies.end());
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
