#include <gtest/gtest.h>

#include "bi_ring.hpp"


TEST(test_temp, test)
{
    auto ring = bi_ring<int, int>();
    ring.clear();

    assert(ring.isEmpty());
}
