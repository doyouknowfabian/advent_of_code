#include "utils/ReadTextFile.h"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace AOC::utils
{

std::vector<std::string> ReadTextFileToLines(const std::string& filename)
{
    std::vector<std::string> lines;
    std::ifstream file(std::string(std::getenv("AOC")) + filename);

    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << std::filesystem::current_path() / filename << std::endl;
        return lines;
    }

    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

} // namespace AOC::utils
