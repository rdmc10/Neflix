#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

class database
{
public:
	void CSVReadLine(std::vector<std::string> movieColumns, std::string line);
	void CSVReadFile(std::string csvPath);
};

