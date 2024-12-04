#include <gtest/gtest.h>

#include "biRingFixture.hpp"
#include "biRing.hpp"
#include "brUsage.hpp"


bool pred(const std::string& key) {
    const int number = std::stoi(key);
    return number % 2 == 0;
}

template <typename Key, typename Info>
Info aggregate(const Key& key, const Info& info1, const Info& info2) {
    return info1 * info2;
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
    auto it = result.cbegin();
    ASSERT_EQ(it++.getKey(), "0");
    ASSERT_EQ(it++.getKey(), "2");
    ASSERT_EQ(it++.getKey(), "4");
    ASSERT_EQ(it++.getKey(), "0");
}

// JOINING
TEST_F(BiRingFixture, BiRingUsage_Join_Empty)
{
    const auto result = join(biRing, biRing);
    ASSERT_TRUE(result.isEmpty());
}

TEST_F(BiRingFixture, BiRingUsage_Join_OneElement)
{
    insertNodes(biRing, 1, 1);
    const auto result = join(biRing, biRing);
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.begin().getKey(), "1");
    ASSERT_EQ(result.begin().getInfo(), 2);
}

TEST_F(BiRingFixture, BiRingUsage_Join_MultipleElements)
{
    insertNodes(biRing, 5);
    auto biRingTwo = createEmptyRing();
    insertNodes(biRingTwo, 4, 2);
    const auto result = join(biRing, biRingTwo);
    ASSERT_EQ(result.size(), 6);
    auto it = result.cbegin();
    ASSERT_EQ(it.getKey(), "0");
    ASSERT_EQ(it++.getInfo(), 0);
    ASSERT_EQ(it.getKey(), "1");
    ASSERT_EQ(it++.getInfo(), 1);
    ASSERT_EQ(it.getKey(), "2");
    ASSERT_EQ(it++.getInfo(), 4);
    ASSERT_EQ(it.getKey(), "3");
    ASSERT_EQ(it++.getInfo(), 6);
    ASSERT_EQ(it.getKey(), "4");
    ASSERT_EQ(it++.getInfo(), 8);
    ASSERT_EQ(it.getKey(), "5");
    ASSERT_EQ(it++.getInfo(), 5);
}

// UNIQUE
TEST_F(BiRingFixture, BiRingUsage_Unique_Empty)
{
    const auto result = unique(biRing, aggregate);
    ASSERT_TRUE(result.isEmpty());
}

TEST_F(BiRingFixture, BiRingUsage_Unique_OneElement)
{
    insertNodes(biRing, 1, 1);
    const auto result = unique(biRing, aggregate);
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.begin().getKey(), "1");
    ASSERT_EQ(result.begin().getInfo(), 1);
}

TEST_F(BiRingFixture, BiRingUsage_Unique_MultipleElements)
{
    insertNodes(biRing, 4);
    insertNodes(biRing, 5, 2);
    const auto result = unique(biRing, aggregate);
    ASSERT_EQ(result.size(), 7);
    auto it = result.cbegin();
    ASSERT_EQ(it.getKey(), "0");
    ASSERT_EQ(it++.getInfo(), 0);
    ASSERT_EQ(it.getKey(), "1");
    ASSERT_EQ(it++.getInfo(), 1);
    ASSERT_EQ(it.getKey(), "2");
    ASSERT_EQ(it++.getInfo(), 4);
    ASSERT_EQ(it.getKey(), "3");
    ASSERT_EQ(it++.getInfo(), 9);
    ASSERT_EQ(it.getKey(), "4");
    ASSERT_EQ(it++.getInfo(), 4);
    ASSERT_EQ(it.getKey(), "5");
    ASSERT_EQ(it++.getInfo(), 5);
    ASSERT_EQ(it.getKey(), "6");
    ASSERT_EQ(it++.getInfo(), 6);
}

// SHUFFLE
TEST_F(BiRingFixture, BiRingUsage_Shuffle_Empty)
{
    const auto result = shuffle(biRing, 1, biRing, 1, 1);
    ASSERT_TRUE(result.isEmpty());
}

TEST_F(BiRingFixture, BiRingUsage_Shuffle_OneElement)
{
    auto biRingTwo = createEmptyRing();
    insertNodes(biRing, 1, 0);
    insertNodes(biRingTwo, 2, 1);
    const auto result = shuffle(biRing, 2, biRingTwo, 1, 2);
    auto it = result.cbegin();
    ASSERT_EQ(result.size(), 6);
    ASSERT_EQ(it.getKey(), "0");
    ASSERT_EQ(it++.getInfo(), 0);
    ASSERT_EQ(it.getKey(), "0");
    ASSERT_EQ(it++.getInfo(), 0);
    ASSERT_EQ(it.getKey(), "1");
    ASSERT_EQ(it++.getInfo(), 1);
    ASSERT_EQ(it.getKey(), "0");
    ASSERT_EQ(it++.getInfo(), 0);
    ASSERT_EQ(it.getKey(), "0");
    ASSERT_EQ(it++.getInfo(), 0);
    ASSERT_EQ(it.getKey(), "2");
    ASSERT_EQ(it++.getInfo(), 2);
}

TEST_F(BiRingFixture, BiRingUsage_Shuffle_MultipleElements)
{
    auto biRingTwo = createEmptyRing();
    insertNodes(biRing, 2, 0);
    insertNodes(biRingTwo, 3, 1);
    const auto result = shuffle(biRing, 2, biRingTwo, 2, 2);
    auto it = result.cbegin();
    ASSERT_EQ(result.size(), 8);
    ASSERT_EQ(it.getKey(), "0");
    ASSERT_EQ(it++.getInfo(), 0);
    ASSERT_EQ(it.getKey(), "1");
    ASSERT_EQ(it++.getInfo(), 1);
    ASSERT_EQ(it.getKey(), "1");
    ASSERT_EQ(it++.getInfo(), 1);
    ASSERT_EQ(it.getKey(), "2");
    ASSERT_EQ(it++.getInfo(), 2);
    ASSERT_EQ(it.getKey(), "0");
    ASSERT_EQ(it++.getInfo(), 0);
    ASSERT_EQ(it.getKey(), "1");
    ASSERT_EQ(it++.getInfo(), 1);
    ASSERT_EQ(it.getKey(), "3");
    ASSERT_EQ(it++.getInfo(), 3);
    ASSERT_EQ(it.getKey(), "1");
    ASSERT_EQ(it++.getInfo(), 1);
}

// FILTER TASK
TEST_F(BiRingFixture, BiRingUsage_FilterTask_Empty)
{
    const auto result = filter(biRing, 0, 1);
    ASSERT_TRUE(result.isEmpty());
}

TEST_F(BiRingFixture, BiRingUsage_FilterTask_OneElementMatch)
{
    insertNodes(biRing, 5);
    const auto result = filter(biRing, 1, 3);
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.begin().getKey(), "2");
}

TEST_F(BiRingFixture, BiRingUsage_FilterTask_OneElementNoMatch)
{
    insertNodes(biRing, 4, 1);
    const auto result = filter(biRing, 0, 1);
    ASSERT_TRUE(result.isEmpty());
}

TEST_F(BiRingFixture, BiRingUsage_FilterTask_MultipleElementsMatch)
{
    insertNodes(biRing, 8);
    const auto result = filter(biRing, 1, 5);
    ASSERT_EQ(result.size(), 3);
    auto it = result.cbegin();
    ASSERT_EQ(it.getKey(), "2");
    ASSERT_EQ(it++.getInfo(), 2);
    ASSERT_EQ(it.getKey(), "3");
    ASSERT_EQ(it++.getInfo(), 3);
    ASSERT_EQ(it.getKey(), "4");
    ASSERT_EQ(it++.getInfo(), 4);
}