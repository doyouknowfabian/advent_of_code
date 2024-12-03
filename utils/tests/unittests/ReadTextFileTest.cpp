#include "utils/ReadTextFile.h"

#include <gtest/gtest.h>

TEST(UtilsTest, ReadTextFile)
{
    std::vector<std::string> fileLines = AOC::utils::ReadTextFileToLines("../tests/data/test0.txt");
    EXPECT_EQ(fileLines.size(), 5);
    EXPECT_EQ(fileLines[0], "a");
    EXPECT_EQ(fileLines[1], "b");
    EXPECT_EQ(fileLines[2], "c");
    EXPECT_EQ(fileLines[3], "abc");
    EXPECT_EQ(fileLines[4], "def");
}
