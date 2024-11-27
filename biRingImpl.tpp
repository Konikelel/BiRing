#ifndef BI_RING_IMPL_H
#define BI_RING_IMPL_H


#include "biRing.hpp"

template <typename Key, typename Info>
biRing<Key, Info>::biRing(const biRing& src): biRing()
{
}

template <typename Key, typename Info>
biRing<Key, Info>::~biRing()
{
    clear();
}

template <typename Key, typename Info>
bool biRing<Key, Info>::clear()
{
    if (this->isEmpty())
    {
        return false;
    }
    
    for (iterator it = this->begin(); it.isValid();)
    {
        it = this->remove(it);
    }

    return true;
}

template <typename Key, typename Info>
size_t biRing<Key, Info>::size() const
{
    return this->count;
}

template <typename Key, typename Info>
bool biRing<Key, Info>::isEmpty() const
{
    return !this->size();
}

template <typename Key, typename Info>
typename biRing<Key, Info>::iterator biRing<Key, Info>::begin() const
{
    return !this->isEmpty() ? iterator(this->pStart, this): iterator();
}

template <typename Key, typename Info>
typename biRing<Key, Info>::constIterator biRing<Key, Info>::cbegin() const
{
    iterator it = this->begin();
    return constIterator(it.pCurr, it.pRing);
}

template <typename Key, typename Info>
bool biRing<Key, Info>::exist(const Key& key, const unsigned int occ) const
{
    return this->get(key, occ).isValid();
}

template <typename Key, typename Info>
typename biRing<Key, Info>::iterator biRing<Key, Info>::get(const Key& key, unsigned int occ) const
{
    iterator it = this->begin();
    for (int nr = 0; nr < this->count; ++nr, ++it)
    {
        if(it.pCurr->key == key && !--occ)
        {
            return it;
        }
    }
    return iterator();
}

template <typename Key, typename Info>
typename biRing<Key, Info>::constIterator biRing<Key, Info>::cget(const Key& key, const unsigned int occ) const
{
    iterator it = this->get(key, occ);
    return constIterator(it.pCurr, it.pRing);
}

template <typename Key, typename Info>
typename biRing<Key, Info>::Node* biRing<Key, Info>::insert(Node* target, const Key& key, const Info& info)
{
    Node* newNode = new Node(key, info, target, target->next);
    newNode->next = target->next;
    target->prev = newNode;
    ++this->count;
    return newNode;
}

template <typename Key, typename Info>
typename biRing<Key, Info>::constIterator biRing<Key, Info>::insert(baseIterator& target, const Key& key, const Info& info)
{
    if (!target.isValid() || this->isForeignIter(target))
    {
        return constIterator();
    }
    Node* newNode = this->insert(target, key, info);
    return constIterator(newNode, this);
}

template <typename Key, typename Info>
typename biRing<Key, Info>::Node* biRing<Key, Info>::remove(Node* target)
{
    Node* nextNode = target->next;
    if (target->prev != target->next)
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    else
    {
        this->pStart = nullptr;
    }
    if (this->pStart == target)
    {
        this->pStart = nextNode;
    }
    delete target;
    --this->count;
    return nextNode;
}

template <typename Key, typename Info>
typename biRing<Key, Info>::constIterator biRing<Key, Info>::remove(baseIterator& target)
{
    if (!target.isValid() || this->isForeignIter(target))
    {
        return constIterator();
    }
    Node* nextNode = this->remove(target.pCurr);
    return constIterator(nextNode, this);
}

template <typename Key, typename Info>
biRing<Key, Info>& biRing<Key, Info>::operator=(const biRing& src)
{
    if (this != &src)
    {
        iterator itForeign = src.begin();
        for (int nr = 0; nr < src.count; ++nr, ++itForeign)
        {
            this->insert(this.pStart, itForeign.pCurr->key, itForeign.pCurr->info);
        }
    }
    return *this;
}

template <typename Key, typename Info>
bool biRing<Key, Info>::isForeignIter(const baseIterator& it) const
{
    return it.pRing == this;
}

#endif //BI_RING_IMPL_H
