#include <gtest/gtest.h>

#include "biRingFixture.hpp"
#include "biRing.hpp"


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
TEST_F(BiRingFixture, BiRing_Destructor_Empty)
{
    ASSERT_NO_THROW(biRing.~BiRing());
}

// CLEAR
TEST_F(BiRingFixture, BiRing_Clear_Empty)
{
    ASSERT_FALSE(biRing.clear());
}

TEST_F(BiRingFixture, BiRing_Clear_OneElementList)
{
    insertNodes(biRing, 1);
    ASSERT_TRUE(biRing.clear());
    ASSERT_TRUE(biRing.isEmpty());
}

TEST_F(BiRingFixture, BiRing_Clear_MultipleElementsList)
{
    insertNodes(biRing, 5);
    ASSERT_TRUE(biRing.clear());
    ASSERT_TRUE(biRing.isEmpty());
}

// SIZE
TEST_F(BiRingFixture, BiRing_Size_Empty)
{
    ASSERT_EQ(biRing.size(), 0);
}

TEST_F(BiRingFixture, BiRing_Size_OneElementList)
{
    insertNodes(biRing, 1);
    ASSERT_EQ(biRing.size(), 1);
}

TEST_F(BiRingFixture, BiRing_Size_MultipleElementsList)
{
    insertNodes(biRing, 5);
    ASSERT_EQ(biRing.size(), 5);
}

// IS EMPTY
TEST_F(BiRingFixture, BiRing_IsEmpty_Empty)
{
    ASSERT_TRUE(biRing.isEmpty());
}

TEST_F(BiRingFixture, BiRing_IsEmpty_NotEmpty)
{
    insertNodes(biRing, 1);
    ASSERT_FALSE(biRing.isEmpty());
}

// BEGIN
TEST_F(BiRingFixture, BiRing_Begin_Empty)
{
    ASSERT_EQ(biRing.begin().isValid(), false);
}

TEST_F(BiRingFixture, BiRing_Begin_OneElementList)
{
    insertNodes(biRing, 1);
    const auto toCheck = biRing.begin();
    ASSERT_EQ(toCheck.isValid(), true);
    ASSERT_EQ(toCheck.getInfo(), 0);
}

TEST_F(BiRingFixture, BiRing_Begin_MultipleElementsList)
{
    insertNodes(biRing, 5);
    const auto toCheck = biRing.begin();
    ASSERT_EQ(toCheck.isValid(), true);
    ASSERT_EQ(toCheck.getInfo(), 4);
}

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