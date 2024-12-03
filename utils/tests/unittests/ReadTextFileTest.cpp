#include "utils/ReadTextFile.h"

#include <gtest/gtest.h>

TEST(UtilsTest, ReadTextFile)
{
    EXPECT_EQ(AOC::utils::ReadTextFileToLines("").size(), 3);
}
