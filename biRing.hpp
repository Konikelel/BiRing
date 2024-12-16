#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


template <typename Key, typename Info>
class BiRing
{
	template <typename Derived>
	class base_iterator;
	
	struct Node {
		Key key;
		Info info;
		Node* next;
		Node* prev;
		Node(const Key& key, const Info& info) : Node(key, info, nullptr, nullptr) {}
		Node(const Key& key, const Info& info, Node* prev, Node* next) : key(key), info(info), next(next), prev(prev) {}
		[[nodiscard]] bool isKeyValueMatch(Node* other) { return this->key == other->key && this->info == other->info; }
	};

	Node* pStart;
	size_t count;
	Node* remove(Node* target);
	Node* insert(Node* target, const Key& key, const Info& info);
public:
	class iterator;
	class const_iterator;
	
	BiRing(): pStart(nullptr), count(0) {}
	BiRing(const BiRing& src): BiRing() { this->append(src); }
	~BiRing() { this->clear(); }

	bool clear();
	[[nodiscard]] size_t size() const { return this->count; }
	[[nodiscard]] bool isEmpty() const { return !this->size(); }
	
	iterator begin() const;
	const_iterator cbegin() const { return this->begin(); }
	bool exist(const Key& key, const unsigned int occ = 1) const { return this->cget(key, occ).isValid(); }

	const_iterator push(const Key& key, const Info& info);
	iterator get(const Key& key, unsigned int occ = 1) const;
	const_iterator cget(const Key& key, const unsigned int occ = 1) const { return this->get(key, occ); }

	iterator remove(iterator& target);
	iterator insert(iterator& target, const Key& key, const Info& info);
	const_iterator cremove(iterator& target) { return this->remove(target); }
	const_iterator cinsert(iterator& target, const Key& key, const Info& info) { return this->insert(target, key, info); }

	BiRing& operator=(const BiRing& src);
	bool append(const BiRing& other);
	void removePairs();
};

#include "biRing.tpp"


#endif // SINGLY_LINKED_LIST_H
