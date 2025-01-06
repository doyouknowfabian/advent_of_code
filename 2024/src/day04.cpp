#include "2024/days.h"
#include "utils/ReadTextFile.h"

#include <iostream>

namespace AOC::Year2024
{
int xmasOccurrences(const std::vector<std::string> matrix, const std::pair<int,int>& coord, int nRows, int nCols)
{
    int occurrences = 0;
    int r = coord.first;
    int c = coord.second;

    std::vector<std::pair<int, int>> directions =
    {
        {-1, 0},    // North
        {-1, 1},    // NE
        {0, 1},     // East
        {1, 1},     // SE
        {1, 0},     // South
        {1, -1},    // SW
        {0, -1},    // West
        {-1, -1},   // NW
    };

    // must consider every direction
    for (auto& dir : directions)
    {
        int dr = dir.first;
        int dc = dir.second;

        // bounds check
        if (r + (dr * 3) < 0 || r + (dr * 3) >= nRows) continue;
        if (c + (dc * 3) < 0 || c + (dc * 3) >= nCols) continue;

        std::string potentialXmas = "X";
        for (int i = 1; i < 4; ++i)
        {
            int newR = r + (dr * i);
            int newC = c + (dc * i);
            potentialXmas += matrix[newR][newC];
        }

        if (potentialXmas == "XMAS") occurrences += 1;
    }

    return occurrences;
}

int crossMasOccurrences(const std::vector<std::string> matrix, const std::pair<int,int>& coord, int nRows, int nCols)
{
    int r = coord.first;
    int c = coord.second;

    // cross XMAS not possible on the edge
    if (r < 1 || r >= nRows - 1) return 0;
    if (c < 1 || c >= nCols - 1) return 0;

    const char neChar = matrix[r-1][c+1];
    const char nwChar = matrix[r-1][c-1];
    const char seChar = matrix[r+1][c+1];
    const char swChar = matrix[r+1][c-1];

    // check vertical match
    if (neChar == nwChar && seChar == swChar)
    {
        // check for pair of M and pair of S
        if (neChar == 'M' && seChar == 'S') return 1;
        if (neChar == 'S' && seChar == 'M') return 1;
    }

    // check horizontal match
    if (neChar == seChar && nwChar == swChar)
    {
        if (neChar == 'M' && nwChar == 'S') return 1;
        if (neChar == 'S' && nwChar == 'M') return 1;
    }

    return 0;
}

void day04()
{
    std::vector<std::string> lines = utils::ReadTextFileToLines("2024/inputs/day4.txt");
    int nRows = lines.size();
    int nCols = lines[0].size();

    std::vector<std::pair<int, int>> allXs;
    std::vector<std::pair<int, int>> allAs;

    // get coords of all Xs
    for (int r = 0; r < nRows; ++r)
    {
        for (int c = 0; c < nCols; ++c)
        {
            if (lines[r][c] == 'X')
            {
                allXs.push_back({r, c});
            }
            else if (lines[r][c] == 'A')
            {
                allAs.push_back({r, c});
            }
        }
    }

    int partOneResult = 0;
    for (auto& xCoord : allXs)
    {
        partOneResult += xmasOccurrences(lines, xCoord, nRows, nCols);
    }
    std::cout << "Part 1: " << partOneResult << std::endl;

    int partTwoResult = 0;
    for (auto& aCoord : allAs)
    {
        partTwoResult += crossMasOccurrences(lines, aCoord, nRows, nCols);
    }
    std::cout << "Part 2: " << partTwoResult << std::endl;

}
} // namespace AOC::Year2024
