#include <gtest/gtest.h>

#include "biRingFixture.hpp"
#include "biRing.hpp"


// BI_RING CONSTRUCTORS
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
    const auto copiedRing = BiRing(biRing);

    ASSERT_EQ(biRing.size(), copiedRing.size());
    ASSERT_EQ(biRing.begin().getKey(), copiedRing.begin().getKey());
}

TEST_F(BiRingFixture, BiRing_CopyConstructor_MultipleElementsList)
{
    insertNodes(biRing, 10);
    const auto copiedRing = BiRing(biRing);

    ASSERT_EQ(biRing.size(), copiedRing.size());
    ASSERT_EQ(biRing.begin().getKey(), copiedRing.begin().getKey());
}

// BI_RING DESTRUCTOR
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
    ASSERT_FALSE(biRing.begin().isValid());
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
    ASSERT_EQ(toCheck.getInfo(), 0);
}

// CBEGIN
TEST_F(BiRingFixture, BiRing_CBegin_Empty)
{
    ASSERT_FALSE(biRing.cbegin().isValid());
}

TEST_F(BiRingFixture, BiRing_CBegin_OneElementList)
{
    insertNodes(biRing, 1);
    const auto toCheck = biRing.cbegin();
    ASSERT_EQ(toCheck.isValid(), true);
    ASSERT_EQ(toCheck.getInfo(), 0);
}

// EXIST
TEST_F(BiRingFixture, BiRing_Exist_Empty)
{
    ASSERT_FALSE(biRing.exist("0"));
}

TEST_F(BiRingFixture, BiRing_Exist_OneElementList)
{
    insertNodes(biRing, 1);
    ASSERT_TRUE(biRing.exist("0"));
}

TEST_F(BiRingFixture, BiRing_Exist_MultipleElementsList)
{
    insertNodes(biRing, 5);
    ASSERT_TRUE(biRing.exist("0"));
    ASSERT_TRUE(biRing.exist("1"));
    ASSERT_TRUE(biRing.exist("2"));
    ASSERT_TRUE(biRing.exist("3"));
    ASSERT_TRUE(biRing.exist("4"));
    ASSERT_FALSE(biRing.exist("5"));
}

// GET
TEST_F(BiRingFixture, BiRing_Get_Empty)
{
    ASSERT_FALSE(biRing.get("0").isValid());
}

TEST_F(BiRingFixture, BiRing_Get_OneElementList)
{
    insertNodes(biRing, 1);
    const auto toCheck = biRing.get("0");
    ASSERT_TRUE(toCheck.isValid());
    ASSERT_EQ(toCheck.getKey(), "0");
}

TEST_F(BiRingFixture, BiRing_Get_MultipleElementsList)
{
    insertNodes(biRing, 5);
    const auto toCheck = biRing.get("2");
    ASSERT_TRUE(toCheck.isValid());
    ASSERT_EQ(toCheck.getKey(), "2");
}

TEST_F(BiRingFixture, BiRing_Get_ElementNotInList)
{
    insertNodes(biRing, 3);
    const auto toCheck = biRing.get("5");
    ASSERT_FALSE(toCheck.isValid());
}

// CGET
TEST_F(BiRingFixture, BiRing_CGet_Empty)
{
    ASSERT_FALSE(biRing.cget("0").isValid());
}

TEST_F(BiRingFixture, BiRing_CGet_OneElementList)
{
    insertNodes(biRing, 1);
    const auto toCheck = biRing.cget("0");
    ASSERT_TRUE(toCheck.isValid());
    ASSERT_EQ(toCheck.getKey(), "0");
}

TEST_F(BiRingFixture, BiRing_CGet_MultipleElementsList)
{
    insertNodes(biRing, 5);
    const auto toCheck = biRing.cget("2");
    ASSERT_TRUE(toCheck.isValid());
    ASSERT_EQ(toCheck.getKey(), "2");
}

TEST_F(BiRingFixture, BiRing_CGet_ElementNotInList)
{
    insertNodes(biRing, 3);
    const auto toCheck = biRing.cget("5");
    ASSERT_FALSE(toCheck.isValid());
}

// PUSH BACK
TEST_F(BiRingFixture, BiRing_PushBack_Empty)
{
    biRing.pushBack("0", 0);
    const auto toCheck = biRing.get("0");
    ASSERT_TRUE(toCheck.isValid());
    ASSERT_EQ(toCheck.getKey(), "0");
    ASSERT_TRUE(*biRing.cbegin() == *toCheck);
}

TEST_F(BiRingFixture, BiRing_PushBack_OneElementList)
{
    insertNodes(biRing, 1);
    biRing.pushBack("1", 1);
    const auto toCheck = biRing.get("1");
    ASSERT_TRUE(toCheck.isValid());
    ASSERT_EQ(toCheck.getKey(), "1");
    ASSERT_FALSE(*biRing.cbegin() == *toCheck);
}

//PUSH FRONT
TEST_F(BiRingFixture, BiRing_PushFront_Empty)
{
    biRing.pushFront("0", 0);
    const auto toCheck = biRing.get("0");
    ASSERT_TRUE(toCheck.isValid());
    ASSERT_EQ(toCheck.getKey(), "0");
    ASSERT_TRUE(*biRing.cbegin() == *toCheck);
}

TEST_F(BiRingFixture, BiRing_PushFront_OneElementList)
{
    insertNodes(biRing, 1);
    biRing.pushFront("1", 1);
    const auto toCheck = biRing.get("1");
    ASSERT_TRUE(toCheck.isValid());
    ASSERT_EQ(toCheck.getKey(), "1");
    ASSERT_TRUE(*biRing.cbegin() == *toCheck);
}

// INSERT
TEST_F(BiRingFixture, BiRing_Insert_OneElementList)
{
    insertNodes(biRing, 1);
    auto itBegin = biRing.begin();
    const auto toCheck = biRing.insert(itBegin, "1", 1);
    ASSERT_EQ(biRing.size(), 2);
    ASSERT_EQ(toCheck.getKey(), "1");
}

TEST_F(BiRingFixture, BiRing_Insert_MultipleElementsList)
{
    insertNodes(biRing, 5);
    auto itBegin = biRing.begin();
    const auto toCheck = biRing.insert(itBegin, "5", 5);
    ASSERT_EQ(biRing.size(), 6);
    ASSERT_EQ(toCheck.getKey(), "5");
}

TEST_F(BiRingFixture, BiRing_Insert_InvalidIterator)
{
    insertNodes(biRing, 5);
    auto it = biRing.getEmptyIterator();
    const auto toCheck = biRing.insert(it, "5", 5);
    ASSERT_EQ(biRing.size(), 5);
    ASSERT_FALSE(toCheck.isValid());
}

TEST_F(BiRingFixture, BiRing_Insert_OtherIterator)
{
    insertNodes(biRing, 5);
    auto biRingOther = createEmptyRing();
    insertNodes(biRingOther, 5);
    auto itOther = biRingOther.begin();
    const auto toCheck = biRing.insert(itOther, "5", 5);
    ASSERT_EQ(biRing.size(), 5);
    ASSERT_FALSE(toCheck.isValid());
}

// REMOVE
TEST_F(BiRingFixture, BiRing_Remove_OneElementList)
{
    insertNodes(biRing, 1);
    auto itBegin = biRing.begin();
    const auto toCheck = biRing.remove(itBegin);
    ASSERT_TRUE(biRing.isEmpty());
    ASSERT_FALSE(itBegin.isValid());
    ASSERT_FALSE(toCheck.isValid());
}

TEST_F(BiRingFixture, BiRing_Remove_MultipleElementsList)
{
    insertNodes(biRing, 5);
    auto itBegin = biRing.begin();
    const auto toCheck = biRing.remove(itBegin);
    ASSERT_EQ(biRing.size(), 4);
    ASSERT_FALSE(itBegin.isValid());
    ASSERT_TRUE(toCheck.isValid());
}

TEST_F(BiRingFixture, BiRing_Remove_OtherIterator)
{
    insertNodes(biRing, 5);
    auto biRingOther = createEmptyRing();
    insertNodes(biRingOther, 5);
    auto itOther = biRingOther.begin();
    const auto toCheck = biRing.remove(itOther);
    ASSERT_EQ(biRing.size(), 5);
    ASSERT_FALSE(toCheck.isValid());
}

// OPERATOR=
TEST_F(BiRingFixture, BiRing_OperatorAssign_Empty)
{
    const BiRing<std::string, int> biRingOther;
    biRing = biRingOther;
    ASSERT_TRUE(biRing.isEmpty());
}

TEST_F(BiRingFixture, BiRing_OperatorAssign_OneElementList)
{
    insertNodes(biRing, 1);
    const BiRing<std::string, int> biRingOther = biRing;
    ASSERT_EQ(biRing.size(), biRingOther.size());
}

TEST_F(BiRingFixture, BiRing_OperatorAssign_MultipleElementsList)
{
    insertNodes(biRing, 5);
    const BiRing<std::string, int> biRingOther = biRing;
    ASSERT_EQ(biRing.size(), biRingOther.size());
}

// APPEND
TEST_F(BiRingFixture, BiRing_Append_Empty)
{
    const BiRing<std::string, int> biRingOther;
    ASSERT_FALSE(biRing.append(biRingOther));
}

TEST_F(BiRingFixture, BiRing_Append_OneElementList)
{
    insertNodes(biRing, 1);
    BiRing<std::string, int> toCheck;
    insertNodes(toCheck, 1, 1);
    ASSERT_TRUE(toCheck.append(biRing));
    ASSERT_EQ(toCheck.size(), 2);
    auto it = toCheck.begin();
    ASSERT_EQ(it++.getKey(), "1");
    ASSERT_EQ(it++.getKey(), "0");
}

TEST_F(BiRingFixture, BiRing_Append_MultipleElementsList)
{
    insertNodes(biRing, 2);
    BiRing<std::string, int> toCheck;
    insertNodes(toCheck, 2, 2);
    ASSERT_TRUE(toCheck.append(biRing));
    ASSERT_EQ(toCheck.size(), 4);
    auto it = toCheck.begin();
    ASSERT_EQ(it++.getKey(), "2");
    ASSERT_EQ(it++.getKey(), "3");
    ASSERT_EQ(it++.getKey(), "0");
    ASSERT_EQ(it++.getKey(), "1");
}
