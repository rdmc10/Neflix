#pragma once
#include <sstream>
#include <string>
#include <vector>

inline std::vector<std::string> ParseString (const std::string& str) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, ',')) {
        result.push_back(item);
    }
    return result;
}


