#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


#include <iostream>

template <typename Key, typename Info>
class BiRing
{
	struct Node {
		Key key;
		Info info;
		Node* next;
		Node* prev;
		Node(const Key& key, const Info& info) : Node(key, info, nullptr, nullptr) {}
		Node(const Key& key, const Info& info, Node* prev, Node* next) : key(key), info(info), next(next), prev(prev) {}
	};
	Node* pStart;
	size_t count;

	class base_iterator
	{
	public:
		base_iterator() : pCurr(nullptr), pRing(nullptr) {}
		base_iterator(Node* node, const BiRing* ring) : pCurr(node), pRing(ring) {}
		virtual ~base_iterator() = default;

		virtual base_iterator& operator++();
		virtual base_iterator& operator--();
		virtual base_iterator operator++(int);
		virtual base_iterator operator--(int);
		virtual base_iterator operator+(int nr);
		virtual base_iterator operator-(int nr);
		virtual base_iterator& operator+=(int nr);
		virtual base_iterator& operator-=(int nr);
		base_iterator& operator=(const base_iterator& other);

		[[nodiscard]] bool isValid() const { return this->pCurr != nullptr; }
		bool operator==(const base_iterator& other) const { return this->pCurr == other.pCurr; }
		bool operator!=(const base_iterator& other) const { return this->pCurr != other.pCurr; }
		friend BiRing;
	protected:
		Node* pCurr;
		const BiRing* pRing;
		
		virtual base_iterator& move(bool forward);
		virtual base_iterator& move(base_iterator& obj, int nr);
		virtual base_iterator& move(int nr);
	};

	Node* remove(Node* target);
	Node* insert(Node* target, const Key& key, const Info& info);
public:
	class iterator final : public base_iterator
	{
	public:
		using base_iterator::base_iterator;
		using base_iterator::operator=;
		Key& getKey() const { return this->pCurr->key; }
		Info& getInfo() const { return this->pCurr->info; }
		Info& operator*() const { return this->pCurr->info; }
	};
	
	class const_iterator final : public base_iterator
	{
	public:
		using base_iterator::base_iterator;
		using base_iterator::operator=;
		const Key& getKey() const { return this->pCurr->key; }
		const Info& getInfo() const { return this->pCurr->info; }
		const Info& operator*() const { return this->pCurr->info; }
	};
	
	BiRing(): pStart(nullptr), count(0) {}
	BiRing(const BiRing& src);
	~BiRing();

	bool clear();
	[[nodiscard]] size_t size() const;
	[[nodiscard]] bool isEmpty() const;
	iterator begin() const;
	const_iterator cbegin() const;
	bool exist(const Key& key, unsigned int occ = 1) const;

	iterator get(const Key& key, unsigned int occ = 1) const;
	const_iterator cget(const Key& key, unsigned int occ = 1) const;

	const_iterator push(const Key& key, const Info& info);

	//TODO: Check if return iterator for popFront, popBack and erase
	//TODO: What if the position iterator belongs to another bi_ring?
	const_iterator insert(base_iterator& target, const Key& key, const Info& info);
	const_iterator remove(base_iterator& target);
	
	BiRing& operator=(const BiRing& src);

	template <typename K, typename I>
	friend std::ostream& operator<<(std::ostream& os, const BiRing<K, I>& ring);
private:
	bool isOtherIter(const base_iterator& it) const;
	bool append(const BiRing& other);
};

#include "biRingImpl.tpp"
#include "biRingImplIterators.tpp"


#endif // SINGLY_LINKED_LIST_H
