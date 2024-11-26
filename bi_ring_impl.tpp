#ifndef BI_RING_IMPL_H
#define BI_RING_IMPL_H


template <typename Key, typename Info>
bi_ring<Key, Info>::bi_ring(const bi_ring& src): bi_ring()
{
}

template <typename Key, typename Info>
bi_ring<Key, Info>::~bi_ring()
{
}

template <typename Key, typename Info>
bool bi_ring<Key, Info>::clear()
{
}

template <typename Key, typename Info>
size_t bi_ring<Key, Info>::size() const
{
    return this->count;
}

template <typename Key, typename Info>
bool bi_ring<Key, Info>::isEmpty() const
{
    return !this->size();
}

template <typename Key, typename Info>
typename bi_ring<Key, Info>::iterator& bi_ring<Key, Info>::begin() const
{
    
}

template <typename Key, typename Info>
typename bi_ring<Key, Info>::const_iterator& bi_ring<Key, Info>::cbegin() const
{
}

template <typename Key, typename Info>
bool bi_ring<Key, Info>::exist(const Key& key, unsigned int occ) const
{
}

template <typename Key, typename Info>
typename bi_ring<Key, Info>::iterator& bi_ring<Key, Info>::get(const Key& key, unsigned int occ) const
{
}

template <typename Key, typename Info>
typename bi_ring<Key, Info>::const_iterator& bi_ring<Key, Info>::cget(const Key& key, unsigned int occ) const
{
}

template <typename Key, typename Info>
bool bi_ring<Key, Info>::get(const Key& key, iterator& result, unsigned int occ) const
{
}

template <typename Key, typename Info>
bool bi_ring<Key, Info>::cget(const Key& key, const_iterator& result, unsigned int occ) const
{
}

template <typename Key, typename Info>
typename bi_ring<Key, Info>::const_iterator bi_ring<Key, Info>::insert(iterator& target, const Key& key,
    const Info& info)
{
}

template <typename Key, typename Info>
typename bi_ring<Key, Info>::iterator bi_ring<Key, Info>::remove(iterator& target)
{
}

template <typename Key, typename Info>
bi_ring<Key, Info>& bi_ring<Key, Info>::operator=(const bi_ring& src)
{
}

#endif //BI_RING_IMPL_H
