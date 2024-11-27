#ifndef BI_RING_IMPL_ITERATORS_H
#define BI_RING_IMPL_ITERATORS_H


#include <stdexcept>

#include "biRing.hpp"

template <typename Key, typename Info>
template <typename Derived>
Derived BiRing<Key, Info>::base_iterator<Derived>::operator++(int)
{
	auto temp = static_cast<Derived>(*this);
	this->operator++();
	return temp;
}

template <typename Key, typename Info>
template <typename Derived>
Derived BiRing<Key, Info>::base_iterator<Derived>::operator--(int)
{
	auto temp = static_cast<Derived>(*this);
	this->operator--();
	return temp;
}

template <typename Key, typename Info>
template <typename Derived>
Derived BiRing<Key, Info>::base_iterator<Derived>::operator+(const int nr)
{
	auto temp = static_cast<Derived>(*this);
	return this->move(temp, nr);
}

template <typename Key, typename Info>
template <typename Derived>
Derived BiRing<Key, Info>::base_iterator<Derived>::operator-(const int nr)
{
	auto temp = static_cast<Derived>(*this);
	return this->move(temp, -nr);
}

template <typename Key, typename Info>
template <typename Derived>
Derived& BiRing<Key, Info>::base_iterator<Derived>::operator=(const Derived& other)
{
	if (this != &other) {
		this->pCurr = other.pCurr;
	}
	return static_cast<Derived&>(*this);
}

template <typename Key, typename Info>
template <typename Derived>
Derived& BiRing<Key, Info>::base_iterator<Derived>::move(const bool forward)
{
	if (!this->isValid())
	{
		throw std::runtime_error("Cannot move not valid baseIterator");
	}
	this->pCurr = forward ? this->pCurr->next : this->pCurr->prev;
	return static_cast<Derived&>(*this);
}

template <typename Key, typename Info>
template <typename Derived>
Derived& BiRing<Key, Info>::base_iterator<Derived>::move(Derived& obj, const int nr)
{
	for(int i = 0; i < nr; ++i)
	{
		obj.move(nr > 0);
	}
	return obj;
}

template <typename Key, typename Info>
template <typename Derived>
Derived& BiRing<Key, Info>::base_iterator<Derived>::move(const int nr)
{
	return this->move(static_cast<Derived&>(*this), nr);
}

#endif //BI_RING_IMPL_ITERATORS_H
