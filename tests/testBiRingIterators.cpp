#include <gtest/gtest.h>

#include "biRingFixture.hpp"
#include "biRing.hpp"


// CONSTRUCTORS
TEST_F(BiRingFixture, BiRingIterators_Constructor_InitializeEmpty)
{
    const auto it = biRing.getEmptyIterator();
    const auto itConst = biRing.getEmptyConstIterator();
    ASSERT_FALSE(it.isValid());
    ASSERT_FALSE(itConst.isValid());
}

// OPERATOR++
TEST_F(BiRingFixture, BiRingIterators_OperatorIncrement_Empty)
{
    auto it = biRing.getEmptyIterator();
    ASSERT_THROW(++it, std::runtime_error);
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorIncrement_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    ASSERT_NO_THROW(++it);
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "1");
    ASSERT_NO_THROW(++it);
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "2");
}

// OPERATOR--
TEST_F(BiRingFixture, BiRingIterators_OperatorDecrement_Empty)
{
    auto it = biRing.getEmptyIterator();
    ASSERT_THROW(--it, std::runtime_error);
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorDecrement_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    ASSERT_NO_THROW(--it);
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "2");
    ASSERT_NO_THROW(--it);
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "1");
}

// OPERATOR++(INT)
TEST_F(BiRingFixture, BiRingIterators_OperatorIncrementPostfix_Empty)
{
    auto it = biRing.getEmptyIterator();
    ASSERT_THROW(it++, std::runtime_error); //NOLINT
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorIncrementPostfix_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    ASSERT_NO_THROW(it++); //NOLINT
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "1");
    ASSERT_NO_THROW(it++); //NOLINT
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "2");
}

// OPERATOR--(INT)
TEST_F(BiRingFixture, BiRingIterators_OperatorDecrementPostfix_Empty)
{
    auto it = biRing.getEmptyIterator();
    ASSERT_THROW(it--, std::runtime_error); //NOLINT
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorDecrementPostfix_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    ASSERT_NO_THROW(it--); //NOLINT
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "2");
    ASSERT_NO_THROW(it--); //NOLINT
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "1");
}

// OPERATOR+(INT NR)
TEST_F(BiRingFixture, BiRingIterators_OperatorPlus_Empty)
{
    auto it = biRing.getEmptyIterator();
    ASSERT_THROW(it + 1, std::runtime_error);
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorPlus_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    const auto toCheck = it + 2;
    ASSERT_EQ(toCheck.getKey(), "2");
}

// OPERATOR-(INT NR)
TEST_F(BiRingFixture, BiRingIterators_OperatorMinus_Empty)
{
    auto it = biRing.getEmptyIterator();
    ASSERT_THROW(it - 1, std::runtime_error);
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorMinus_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    const auto toCheck = it - 2;
    ASSERT_EQ(toCheck.getKey(), "1");
}


// OPERATOR+=(INT NR)
TEST_F(BiRingFixture, BiRingIterators_OperatorPlusEqual_Empty)
{
    auto it = biRing.getEmptyIterator();
    ASSERT_THROW(it += 1, std::runtime_error);
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorPlusEqual_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    ASSERT_NO_THROW(it += 2);
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "2");
}

// OPERATOR-=(INT NR)
TEST_F(BiRingFixture, BiRingIterators_OperatorMinusEqual_Empty)
{
    auto it = biRing.getEmptyIterator();
    ASSERT_THROW(it -= 1, std::runtime_error);
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorMinusEqual_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    ASSERT_NO_THROW(it -= 2);
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "1");
}

// OPERATOR=
TEST_F(BiRingFixture, BiRingIterators_OperatorAssign_Empty)
{
    auto it = biRing.getEmptyIterator();
    const auto it2 = biRing.getEmptyIterator();
    it = it2;
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorAssign_MultipleElementList)
{
    insertNodes(biRing, 3);
    const auto it = biRing.begin();
    const BiRing<std::string, int>::iterator& toCheck = it;
    ASSERT_TRUE(toCheck.isValid());
    ASSERT_EQ(toCheck.getKey(), "0");
}

// ISVALID
TEST_F(BiRingFixture, BiRingIterators_IsValid_Empty)
{
    const auto it = biRing.getEmptyIterator();
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_IsValid_NotEmpty)
{
    insertNodes(biRing, 3);
    const auto it = biRing.begin();
    ASSERT_TRUE(it.isValid());
}

// OPERATOR==
TEST_F(BiRingFixture, BiRingIterators_OperatorEqual_Empty)
{
    const auto it = biRing.getEmptyIterator();
    const auto it2 = biRing.getEmptyIterator();
    ASSERT_TRUE(it == it2);
}

TEST_F(BiRingFixture, BiRingIterators_OperatorEqual_NotEmptyEqual)
{
    insertNodes(biRing, 3);
    const auto it = biRing.begin();
    const auto it2 = biRing.begin();
    ASSERT_TRUE(it == it2);
}

TEST_F(BiRingFixture, BiRingIterators_OperatorEqual_NotEmptyNotEqual)
{
    insertNodes(biRing, 3);
    const auto it = biRing.begin();
    const auto it2 = biRing.begin() + 1;
    ASSERT_FALSE(it == it2);
}

// OPERATOR!=
TEST_F(BiRingFixture, BiRingIterators_OperatorNotEqual_Empty)
{
    const auto it = biRing.getEmptyIterator();
    const auto it2 = biRing.getEmptyIterator();
    ASSERT_FALSE(it != it2);
}

TEST_F(BiRingFixture, BiRingIterators_OperatorNotEqual_NotEmptyEqual)
{
    insertNodes(biRing, 3);
    const auto it = biRing.begin();
    const auto it2 = biRing.begin();
    ASSERT_FALSE(it != it2);
}

TEST_F(BiRingFixture, BiRingIterators_OperatorNotEqual_NotEmptyNotEqual)
{
    insertNodes(biRing, 3);
    const auto it = biRing.begin();
    const auto it2 = biRing.begin() + 1;
    ASSERT_TRUE(it != it2);
}