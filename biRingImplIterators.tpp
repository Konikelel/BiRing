#ifndef BI_RING_IMPL_ITERATORS_H
#define BI_RING_IMPL_ITERATORS_H


#include <stdexcept>

#include "biRing.hpp"

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator& BiRing<Key, Info>::base_iterator::operator++()
{
	return this->move(true);
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator& BiRing<Key, Info>::base_iterator::operator--()
{
	return this->move(false);
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator BiRing<Key, Info>::base_iterator::operator++(int)
{
	auto temp = *this;
	this->operator++();
	return temp;
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator BiRing<Key, Info>::base_iterator::operator--(int)
{
	auto temp = *this;
	this->operator--();
	return temp;
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator BiRing<Key, Info>::base_iterator::operator+(const int nr)
{
	auto temp = *this;
	return this->move(temp, nr);
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator BiRing<Key, Info>::base_iterator::operator-(const int nr)
{
	auto temp = *this;
	return this->move(temp, -nr);
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator& BiRing<Key, Info>::base_iterator::operator+=(const int nr)
{
	return this->move(nr);
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator& BiRing<Key, Info>::base_iterator::operator-=(const int nr)
{
	return this->move(-nr);
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator& BiRing<Key, Info>::base_iterator::operator=(const base_iterator& other)
{
	if (this != &other) {
		this->pCurr = other.pCurr;
	}
	return *this;
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator& BiRing<Key, Info>::base_iterator::move(const bool forward)
{
	if (!this->isValid())
	{
		throw std::runtime_error("Cannot move not valid baseIterator");
	}
	this->pCurr = forward ? this->pCurr->next : this->pCurr->prev;
	return *this;
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator& BiRing<Key, Info>::base_iterator::move(base_iterator& obj, const int nr)
{
	for(int i = 0; i < nr; ++i)
	{
		obj.move(nr > 0);
	}
	return obj;
}

template <typename Key, typename Info>
typename BiRing<Key, Info>::base_iterator& BiRing<Key, Info>::base_iterator::move(const int nr)
{
	return this->move(*this, nr);
}

#endif //BI_RING_IMPL_ITERATORS_H
