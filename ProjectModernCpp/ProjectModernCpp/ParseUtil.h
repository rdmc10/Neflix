#pragma once
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> ParseString (const std::string& str) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, ',')) {
        result.push_back(item);
    }
    return result;
}

std::string GetFirstWord(const std::string& str) {
    size_t spacePos = str.find(' ');
    std::string firstWord = str.substr(0, spacePos);
    return firstWord;
}