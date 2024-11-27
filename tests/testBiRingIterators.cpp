#include <gtest/gtest.h>

#include "biRingFixture.hpp"
#include "biRing.hpp"


// CONSTRUCTORS
TEST_F(BiRingFixture, BiRingIterators_Constructor_InitializeEmpty)
{
    const auto it = BiRing<std::string, int>::iterator();
    const auto itConst = BiRing<std::string, int>::const_iterator();
    ASSERT_FALSE(it.isValid());
    ASSERT_FALSE(itConst.isValid());
}

// OPERATOR++
TEST_F(BiRingFixture, BiRingIterators_OperatorIncrement_Empty)
{
    auto it = BiRing<std::string, int>::iterator();
    ASSERT_THROW(++it, std::runtime_error);
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorIncrement_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    ASSERT_NO_THROW(++it);
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "0");
    ASSERT_NO_THROW(++it);
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "1");
}

// OPERATOR--
TEST_F(BiRingFixture, BiRingIterators_OperatorDecrement_Empty)
{
    auto it = BiRing<std::string, int>::iterator();
    ASSERT_THROW(--it, std::runtime_error);
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorDecrement_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    ASSERT_NO_THROW(--it);
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "1");
    ASSERT_NO_THROW(--it);
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "0");
}

// OPERATOR++(INT)
TEST_F(BiRingFixture, BiRingIterators_OperatorIncrementPostfix_Empty)
{
    auto it = BiRing<std::string, int>::iterator();
    ASSERT_THROW(it++, std::runtime_error); //NOLINT
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorIncrementPostfix_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    ASSERT_NO_THROW(it++); //NOLINT
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "0");
    ASSERT_NO_THROW(it++); //NOLINT
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "1");
}

// OPERATOR--(INT)
TEST_F(BiRingFixture, BiRingIterators_OperatorDecrementPostfix_Empty)
{
    auto it = BiRing<std::string, int>::iterator();
    ASSERT_THROW(it--, std::runtime_error); //NOLINT
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorDecrementPostfix_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    ASSERT_NO_THROW(it--); //NOLINT
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "1");
    ASSERT_NO_THROW(it--); //NOLINT
    ASSERT_TRUE(it.isValid());
    ASSERT_EQ(it.getKey(), "0");
}

// OPERATOR+(INT NR)
TEST_F(BiRingFixture, BiRingIterators_OperatorPlus_Empty)
{
    auto it = BiRing<std::string, int>::iterator();
    ASSERT_THROW(it + 1, std::runtime_error);
    ASSERT_FALSE(it.isValid());
}

TEST_F(BiRingFixture, BiRingIterators_OperatorPlus_MultipleElementList)
{
    insertNodes(biRing, 3);
    auto it = biRing.begin();
    auto toCheck = it + 2;
    ASSERT_EQ(toCheck.getKey(), "1");
}

// OPERATOR-(INT NR)
// OPERATOR+=(INT NR)
// OPERATOR-=(INT NR)
// OPERATOR=
// ISVALID
// OPERATOR==
// OPERATOR!=