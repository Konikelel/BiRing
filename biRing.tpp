#ifndef BI_RING_IMPL_H
#define BI_RING_IMPL_H


#include "iterators/biRingIterator.hpp"
#include "iterators/biRingConstIterator.hpp"

template <typename Key, typename Info>
bool BiRing<Key, Info>::clear()
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
typename BiRing<Key, Info>::iterator BiRing<Key, Info>::begin() const
{
    return !this->isEmpty() ? iterator(this->pStart, this): iterator();
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::iterator BiRing<Key, Info>::get(const Key& key, unsigned int occ) const
{
    for (auto nr = 0, it = this->begin(); nr < this->count; ++nr, ++it)
    {
        if(it.pCurr->key == key && !--occ)
        {
            return it;
        }
    }
    return iterator();
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::const_iterator BiRing<Key, Info>::pushBack(const Key& key, const Info& info)
{
    Node* newNode = this->insert(this->pStart, key, info);
    return const_iterator(newNode, this);
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::const_iterator BiRing<Key, Info>::pushFront(const Key& key, const Info& info)
{
    auto it = this->pushBack(key, info);
    this->pStart = it.pCurr;
    return it;
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::Node* BiRing<Key, Info>::insert(Node* target, const Key& key, const Info& info)
{
    Node* newNode = new Node(key, info);
    if (this->isEmpty())
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        this->pStart = newNode;
    }
    else
    {
        newNode->next = target;
        newNode->prev = target->prev;
        target->prev->next = newNode;
        target->prev = newNode;
    }
    ++this->count;
    return newNode;
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::iterator BiRing<Key, Info>::insert(iterator& target, const Key& key, const Info& info)
{
    if (!target.isValid() || !target.isInRing(*this))
    {
        return iterator();
    }
    Node* newNode = this->insert(target.pCurr, key, info);
    return iterator(newNode, this);
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::Node* BiRing<Key, Info>::remove(Node* target)
{
    if (target == nullptr) { return nullptr; }
    Node* prevNode = target->prev;
    if (target != target->prev)
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;

        if (this->pStart == target)
        {
            this->pStart = target->next;
        }
    }
    else
    {
        this->pStart = prevNode = nullptr;
    }
    delete target;
    --this->count;
    return prevNode ? prevNode : this->pStart;
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::iterator BiRing<Key, Info>::remove(iterator& target)
{
    if (!target.isValid() || !target.isInRing(*this))
    {
        return iterator();
    }
    Node* prevNode = this->remove(target.pCurr);
    target.pCurr = nullptr;
    return iterator(prevNode, this);
}

template <typename Key, typename Info>
BiRing<Key, Info>& BiRing<Key, Info>::operator=(const BiRing& src)
{
    if (this != &src)
    {
        this->clear();
        this->append(src);
    }
    return *this;
}

template <typename Key, typename Info>
bool BiRing<Key, Info>::append(const BiRing& other)
{
    if(other.isEmpty())
    {
        return false;
    }
    for (auto nr = 0, itOther = other.begin(); nr < other.count; ++nr, ++itOther)
    {
        this->pushBack(itOther.pCurr->key, itOther.pCurr->info);
    }
    return true;
}


#endif //BI_RING_IMPL_H
