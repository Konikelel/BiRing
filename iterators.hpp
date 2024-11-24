#ifndef ITERATORS_H
#define ITERATORS_H


#include <stdexcept>

#include "bi_ring.hpp"

template <typename Key, typename Info>
class iterator final: public const_iterator<Key, Info>
{
public:
	explicit iterator(typename bi_ring<Key, Info>::Node* node) : const_iterator<Key, Info>(node) {}
	
	Info& operator*() override { return this->pCurr->info; }

	iterator& operator=(const iterator& other) {
		if (this != &other) {
			this->pCurr = other.pCurr;
		}
		return *this;
	}
};

template <typename Key, typename Info>
class const_iterator
{
public:
	explicit const_iterator(typename bi_ring<Key, Info>::Node* node) : pCurr(node) {}
	virtual ~const_iterator() = default;
	
	virtual const Info& operator*() { return this->pCurr->info; }

	virtual const_iterator& operator++() { return *this->move(true); }
	virtual const_iterator& operator--() { return *this->move(false); }
	
	virtual const_iterator operator++(int) {
		auto temp = *this;
		this->operator++();
		return temp;
	}
	virtual const_iterator operator--(int) {
		auto temp = *this;
		this->operator--();
		return temp;
	}
	
	virtual const_iterator operator+(const int nr)
	{
		auto temp = *this;
		for (int i = 0; i < nr; ++i)
		{
			temp = temp.move(true);
		}
		return temp;
	}
	virtual const_iterator operator-(const int nr)
	{
		auto temp = *this;
		for (int i = 0; i < nr; ++i)
		{
			temp = temp.move(false);
		}
		return temp;
	}

	virtual const_iterator& operator+=(const int nr)
	{
		for (int i = 0; i < nr; ++i)
		{
			this->move(true);
		}
		return *this;
	}
	virtual const_iterator& operator-=(const int nr)
	{
		for (int i = 0; i < nr; ++i)
		{
			this->move(false);
		}
		return *this;
	}
	
	const_iterator& operator=(const const_iterator& other) {
		if (this != &other) {
			this->pCurr = other.pCurr;
		}
		return *this;
	}
	
	bool operator==(const const_iterator& other) const { return this->pCurr == other.pCurr; }
	bool operator!=(const const_iterator& other) const { return this->pCurr != other.pCurr; }
private:
	typename bi_ring<Key, Info>::Node* pCurr;

	virtual const_iterator& move(bool forward)
	{
		if (this->pCurr == nullptr)
		{
			throw std::runtime_error("Cannot move empty iterator");
		}
		return forward ? ++this->pCurr : --this->pCurr;
	}
};


#endif //ITERATORS_H
