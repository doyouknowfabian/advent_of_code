#include "2024/days.h"
#include "utils/ReadTextFile.h"

#include <iostream>
#include <iterator>
#include <regex>

namespace AOC::Year2024
{
void day3()
{
    std::vector<std::string> lines = utils::ReadTextFileToLines("2024/inputs/day3.txt");

    std::regex mul_pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");

    int multiplications = 0;
    std::string concatenated = "";
    std::vector<std::string> split_by_do;
    std::regex do_pattern("do\\(\\)");
    std::regex dont_pattern("don't\\(\\)");

    for (int i = 0; i < lines.size(); ++i)
    {
        auto mul_begin = std::sregex_iterator(lines[i].begin(), lines[i].end(), mul_pattern);
        auto mul_end = std::sregex_iterator();

        // std::cout << "Found " << std::distance(mul_begin, mul_end) << " words\n";
        for (std::sregex_iterator j = mul_begin; j != mul_end; ++j)
        {
            std::smatch match = *j;
            // std::cout << "match: " << match.str() << std::endl;
            // std::cout << "X: " << match.str(1) << std::endl;
            // std::cout << "Y: " << match.str(2) << std::endl;
            int product = std::stoi(match.str(1)) * std::stoi(match.str(2));
            // std::cout << "X * Y = " << product << std::endl;
            multiplications += product;
        }

        // part two
        concatenated += lines[i];
    }

    std::cout << "Part 1: " << multiplications << std::endl;

    std::sregex_token_iterator it(concatenated.begin(), concatenated.end(), do_pattern, -1);
    std::sregex_token_iterator end;

    while (it != end)
    {
        split_by_do.push_back(*it++);
    }

    // std::cout << split_by_do[0] << std::endl;
    // std::cout << split_by_do[0].substr(0, split_by_do[0].find("don't()")) << std::endl;
    int multiplications_do = 0;
    for (int i = 0; i < split_by_do.size(); ++i)
    {
        size_t pos = split_by_do[i].find("don't()");
        std::string do_muls = split_by_do[i].substr(0, pos);
        auto mul_begin = std::sregex_iterator(do_muls.begin(), do_muls.end(), mul_pattern);
        auto mul_end = std::sregex_iterator();

        for (std::sregex_iterator j = mul_begin; j != mul_end; ++j)
        {
            std::smatch match = *j;
            int product = std::stoi(match.str(1)) * std::stoi(match.str(2));
            multiplications_do += product;
        }
    }

    std::cout << "Part 2: " << multiplications_do << std::endl;

}
} // namespace AOC::Year2024
