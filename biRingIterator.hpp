#ifndef BI_RING_ITERATOR_H
#define BI_RING_ITERATOR_H


#include <algorithm>

#include "biRing.hpp"
#include "biRingBaseIterator.hpp"

template <typename Key, typename Info>
class BiRing<Key, Info>::iterator final : public base_iterator<iterator>
{
public:
    using base_iterator<iterator>::base_iterator;
    iterator(const base_iterator<iterator>& other) //NOLINT
    {
        this->pCurr = other.pCurr;
        this->pRing = other.pRing;
    }
    iterator(base_iterator<iterator>&& other) //NOLINT
    {
        this->pCurr = std::move(other.pCurr);
        this->pRing = std::move(other.pRing);
    }

    Key& getKey() const { return this->pCurr->key; }
    Info& getInfo() const { return this->pCurr->info; }
    Info& operator*() const { return this->pCurr->info; }
};


#endif //BI_RING_ITERATOR_H
