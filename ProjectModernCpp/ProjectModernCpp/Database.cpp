#include "Database.h"

void database::CSVReadLine(std::vector<std::string> movieColumns, std::string line) {
    std::stringstream str(line);
    std::string word;
    while (std::getline(str, word, ','))
    {
        if (word[0] == '"')
        {
            std::string tmp = word;
            while (word[word.size() - 1] != '"')
            {
                std::getline(str, word, ',');
                tmp += ",";
                tmp += word;
            }
            movieColumns.push_back(tmp);
        }
        else movieColumns.push_back(word);
    }
}

void database::CSVReadFile(std::string csvPath)
{
    std::ifstream csvFile(csvPath);
    std::string line;

    std::getline(csvFile, line);

    while (std::getline(csvFile, line))
    {
        std::vector<std::string> movieColumns;
        CSVReadLine(movieColumns, line);
        for (int i = 0; i < movieColumns.size(); i++)
            std::cout << movieColumns[i] << "---------";
        std::cout << "\n";
    }
}
