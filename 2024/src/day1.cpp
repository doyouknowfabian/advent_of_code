#include "2024/days.h"
#include "utils/ReadTextFile.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <unordered_map>

namespace AOC::Year2024
{
void day1()
{
    std::vector<std::string> pairs = utils::ReadTextFileToLines("../inputs/day1.txt");
    assert(pairs[0] == "88276   66757");

    int nPairs = pairs.size();

    std::vector<int> left, right;
    left.reserve(pairs.size());
    right.reserve(pairs.size());
    
    for (int i = 0; i < nPairs; ++i)
    {
        int l, r;
        std::istringstream iss(pairs[i]);
        iss >> l >> r;
        left.push_back(l);
        right.push_back(r);
    }

    assert(left[0] == 88276);
    assert(right[0] == 66757);

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
  
    assert(left[0] <= left[1]);

    int totalDistance = 0;
    for (int i = 0; i < nPairs; ++i)
        totalDistance += (std::abs(left[i] - right[i]));

    std::cout << "Part 1: " << totalDistance << std::endl;

    /// PART TWO ///
    std::unordered_map<int, int> rightCounter;
    int similarityScore = 0;

    for (int i = 0; i < nPairs; ++i)
    {
        if (rightCounter.count(right[i]) == 0)
        {
            rightCounter[right[i]] = 1;
            continue;
        }

        rightCounter[right[i]] += 1;
    }

    for (int i = 0; i < nPairs; ++i)
    {
        if (rightCounter.count(left[i]) > 0)
        {
            similarityScore += left[i] * rightCounter[left[i]];
        }
    }

    std::cout << "Part 2: " << similarityScore << std::endl;
}
} // namespace AOC::2024 

