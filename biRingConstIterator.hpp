#ifndef BI_RING_CONST_ITERATOR_H
#define BI_RING_CONST_ITERATOR_H


#include <algorithm>

#include "biRing.hpp"
#include "biRingBaseIterator.hpp"

template <typename Key, typename Info>
class BiRing<Key, Info>::const_iterator final : public base_iterator<const_iterator>
{
public:
    using base_iterator<const_iterator>::base_iterator;
    const_iterator(const base_iterator<const_iterator>& other) //NOLINT
    {
        this->pCurr = other.pCurr;
        this->pRing = other.pRing;
    }
    const_iterator(base_iterator<const_iterator>&& other) //NOLINT
    {
        this->pCurr = std::move(other.pCurr);
        this->pRing = std::move(other.pRing);
    }
    const_iterator(const iterator& other) //NOLINT
    {
        this->pCurr = other.pCurr;
        this->pRing = other.pRing;
    }
    const_iterator(iterator&& other) //NOLINT
    {
        this->pCurr = std::move(other.pCurr);
        this->pRing = std::move(other.pRing);
    }

    const Key& getKey() const { return this->pCurr->key; }
    const Info& getInfo() const { return this->pCurr->info; }
    const Info& operator*() const { return this->pCurr->info; }
};


#endif //BI_RING_CONST_ITERATOR_H
