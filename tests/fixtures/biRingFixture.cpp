#include "biRingFixture.hpp"

#include "biRing.hpp"
#include "biRingConstIterator.hpp"

void BiRingFixture::insertNodes(BiRing<std::string, int> &ring, const unsigned int number, const unsigned int startNr)
{
    for (unsigned int nr = startNr; nr < number + startNr; nr++)
    {
        ring.push(std::to_string(nr), static_cast<int>(nr));
    }
}

BiRing<std::string, int> BiRingFixture::createEmptyRing()
{
    return {};
}