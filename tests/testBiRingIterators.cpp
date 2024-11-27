#include <gtest/gtest.h>

#include "biRingFixture.hpp"


// BIRING CONSTRUCTORS
TEST_F(BiRingFixture, BiRing_Constructor_InitializeEmpty)
{
    ASSERT_TRUE(biRing.isEmpty());
}

TEST_F(BiRingFixture, BiRing_CopyConstructor_Empty)
{
    const auto toCheck = BiRing(biRing);
    ASSERT_TRUE(toCheck.isEmpty());
}

TEST_F(BiRingFixture, BiRing_CopyConstructor_OneElementList)
{
    insertNodes(biRing, 1);
    const auto copiedList = BiRing(biRing);

    ASSERT_EQ(biRing.size(), copiedList.size());
    ASSERT_EQ(biRing.begin().getKey(), copiedList.begin().getKey());
}

TEST_F(BiRingFixture, BiRing_CopyConstructor_MultipleElementsList)
{
    insertNodes(biRing, 10);
    const auto copiedList = BiRing(biRing);

    ASSERT_EQ(biRing.size(), copiedList.size());
    ASSERT_EQ(biRing.begin().getKey(), copiedList.begin().getKey());
}

// BIRING DESTRUCTOR
// CLEAR
// SIZE
// IS EMPTY
// BEGIN
// CBEGIN
// EXIST
// GET
// CGET
// PUSH
// INSERT
// REMOVE
// OPERATOR=
// OPERATOR<<
// APPEND