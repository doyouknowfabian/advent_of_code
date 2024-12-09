#include "2024/days.h"
#include "utils/ReadTextFile.h"

#include <cmath>
#include <iostream>
#include <sstream>

namespace AOC::Year2024
{
    bool isReportSafe(const std::vector<int>& report)
    {
        // check first two levels to establish increasing or decreasing
        int currentLevelIdx = 1;
        int previousLevel = report[0];
        int currentLevel = report[currentLevelIdx];
        if (previousLevel == currentLevel) return false;
        if (std::abs(previousLevel - currentLevel) > 3) return false;
        bool isIncreasing = previousLevel < currentLevel;

        // assume safe until proven otherwise
        ++currentLevelIdx;
        while (currentLevelIdx < report.size())
        {
            previousLevel = currentLevel;
            currentLevel = report[currentLevelIdx];

            if (previousLevel == currentLevel) return false;

            if (std::abs(previousLevel - currentLevel) > 3) return false;

            if (isIncreasing != previousLevel < currentLevel) return false;

            ++currentLevelIdx;
        }

        return true;


    }

    void day2()
    {
        std::vector<std::string> reports = utils::ReadTextFileToLines("../inputs/day2.txt");
        
        std::vector<bool> reportSafety;

        for (const auto& report : reports) 
        {
            std::vector<int> levels;
            int level;
            std::istringstream iss(report);
            while (iss >> level) levels.push_back(level);
            reportSafety.push_back(isReportSafe(levels));
        }

        int numSafeReports = 0;
        for (const auto isSafe : reportSafety)
            numSafeReports += isSafe;

        std::cout << "Part 1: " << numSafeReports << std::endl;

        int numSafeWithRemovingLevel = 0;
        for (int i = 0; i < reports.size(); ++i)
        {
            if (reportSafety[i]) continue;
          
            // maybe removing one will make it safe
            std::vector<int> levels;
            int level;
            std::istringstream iss(reports[i]);
            while (iss >> level) levels.push_back(level);

            std::vector<std::vector<int>> permutations;
            for (int j = 0; j < levels.size(); ++j)
            {
                std::vector<int> reportWithRemovedLevel;
                for (int k = 0; k < levels.size(); ++k)
                    if (j != k) reportWithRemovedLevel.push_back(levels[k]);
                permutations.push_back(reportWithRemovedLevel);
            }

            for (const auto& permutation : permutations)
            {
                if (isReportSafe(permutation)) 
                {
                    ++numSafeWithRemovingLevel;
                    break;
                }
            }
        }

        std::cout << "Part 2: " << numSafeReports + numSafeWithRemovingLevel << std::endl;
    }
}
