#include "Database.h"
#include <qmainwindow.h>

void database::CSVReadLine(std::vector<std::string>& movieColumns, const std::string& line) {
    std::stringstream lstr(line);
    std::string word;
    while (std::getline(lstr, word, ','))
    {
        if (word[0] == '"')
        {
            std::string tmp = word;
            while (word[word.size() - 1] != '"')
            {
                std::getline(lstr, word, ',');
                tmp += ",";
                tmp += word;
            }
            movieColumns.push_back(tmp);
        }
        else movieColumns.push_back(word);
    }
}

void database::CSVReadFile(const std::string& csvPath)
{
    std::ifstream csvFile(csvPath);
    std::string line;

    std::getline(csvFile, line);

    while (std::getline(csvFile, line))
    {
        std::vector<std::string> movieColumns;
        CSVReadLine(movieColumns, line);
        for (int i = 0; i < movieColumns.size(); i++)
            qDebug() << QString::fromStdString(movieColumns[i]) << "---------";
        qDebug() << "\n";
    }
}
