#ifndef BI_RING_FIXTURE_H
#define BI_RING_FIXTURE_H


#include <gtest/gtest.h>
#include <string>

#include "biRing.hpp"

class BiRingFixture : public testing::Test
{
protected:
    BiRing<std::string, int> biRing;

    static void insertNodes(BiRing<std::string, int> &ring, unsigned int number, unsigned int startNr = 0);

    static BiRing<std::string, int> createEmptyRing();
};


#endif //BI_RING_FIXTURE_H
