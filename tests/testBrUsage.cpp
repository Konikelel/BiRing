#include <gtest/gtest.h>

#include "biRingFixture.hpp"
#include "biRing.hpp"
#include "brUsage.hpp"


bool pred(const std::string& key) {
    const int number = std::stoi(key);
    return number % 2 == 0;
}

// FILTERING
TEST_F(BiRingFixture, BiRingUsage_Filter_Empty)
{
    const auto result = filter(biRing, pred);
    ASSERT_TRUE(result.isEmpty());
}

TEST_F(BiRingFixture, BiRingUsage_Filter_OneElementMatch)
{
    insertNodes(biRing, 1);
    const auto result = filter(biRing, pred);
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.begin().getKey(), "0");
}

TEST_F(BiRingFixture, BiRingUsage_Filter_OneElementNoMatch)
{
    insertNodes(biRing, 1, 1);
    const auto result = filter(biRing, pred);
    ASSERT_TRUE(result.isEmpty());
}

TEST_F(BiRingFixture, BiRingUsage_Filter_MultipleElements)
{
    insertNodes(biRing, 5);
    const auto result = filter(biRing, pred);
    ASSERT_EQ(result.size(), 3);
    auto it = result.begin();
    ASSERT_EQ(it++.getKey(), "0");
    ASSERT_EQ(it++.getKey(), "2");
    ASSERT_EQ(it++.getKey(), "4");
    ASSERT_EQ(it++.getKey(), "0");
}

// JOINING
// UNIQUE
// SHUFFLE