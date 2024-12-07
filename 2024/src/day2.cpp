#include "2024/days.h"
#include "utils/ReadTextFile.h"

#include <cmath>
#include <iostream>
#include <sstream>

namespace AOC::Year2024
{
    void day2()
    {
        std::vector<std::string> reports = utils::ReadTextFileToLines("../inputs/day2.txt");
        
        std::vector<bool> isReportSafe;

        for (const auto& report : reports) {
            int prevLevel, level;
            std::istringstream iss(report);
            iss >> prevLevel;
            iss >> level;
            if (prevLevel == level)
            {
                isReportSafe.push_back(false);
                continue;
            }
            if (std::abs(prevLevel - level) > 3)
            {
                isReportSafe.push_back(false);
                continue;
            }
            bool isIncreasing = prevLevel < level;
            bool isSafe = true;
            prevLevel = level;
            while (iss >> level)
            {
                if (prevLevel == level)
                {
                    isSafe = false;
                    break;
                }

                if (std::abs(prevLevel - level) > 3)
                {
                    isSafe = false;
                    break;
                }

                if (isIncreasing != prevLevel < level)
                {
                    isSafe = false;
                    break;
                }
                prevLevel = level;
            }

            if (!isSafe)
            {
                isReportSafe.push_back(false);
                continue;
            }

            isReportSafe.push_back(true);
        }
        int numSafeReports = 0;
        for (const auto isSafe : isReportSafe)
            numSafeReports += isSafe;

        std::cout << "Part 1: " << numSafeReports << std::endl;
    }
}
