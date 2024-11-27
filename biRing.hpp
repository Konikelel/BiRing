#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


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

	template <typename Derived>
	class base_iterator //NOLINT
	{
	public:
		base_iterator() : pCurr(nullptr), pRing(nullptr) {}
		base_iterator(Node* node, const BiRing* ring) : pCurr(node), pRing(ring) {}
		virtual ~base_iterator() = default;

		virtual Derived& operator++() { return this->move(true); }
		virtual Derived& operator--() { return this->move(false); }
		virtual Derived operator++(int);
		virtual Derived operator--(int);
		virtual Derived operator+(int nr);
		virtual Derived operator-(int nr);
		virtual Derived& operator+=(const int nr) { return this->move(nr); }
		virtual Derived& operator-=(const int nr) { return this->move(-nr); }
		Derived& operator=(const Derived& other);

		[[nodiscard]] bool isValid() const { return this->pCurr != nullptr; }
		[[nodiscard]] bool isInRing(const BiRing& ring) { return this->pRing == &ring; }
		bool operator==(const Derived& other) const { return this->pCurr == other.pCurr; }
		bool operator!=(const Derived& other) const { return this->pCurr != other.pCurr; }
		friend BiRing;
	protected:
		Node* pCurr;
		const BiRing* pRing;
		
		virtual Derived& move(bool forward);
		virtual Derived& move(Derived& obj, int nr);
		virtual Derived& move(int nr);
	};

	Node* remove(Node* target);
	Node* insert(Node* target, const Key& key, const Info& info);
public:
	class iterator final : public base_iterator<iterator>
	{
	public:
		iterator(base_iterator<iterator>& other) { this->pCurr = other.pCurr; this->pRing = other.pRing; }
		iterator(base_iterator<iterator>&& other) { this->pCurr = std::move(other.pCurr); this->pRing = std::move(other.pRing); }
		using base_iterator<iterator>::base_iterator;
		Key& getKey() const { return this->pCurr->key; }
		Info& getInfo() const { return this->pCurr->info; }
		Info& operator*() const { return this->pCurr->info; }
	};
	
	class const_iterator final : public base_iterator<const_iterator>
	{
	public:
		const_iterator(base_iterator<const_iterator>& other) { this->pCurr = other.pCurr; this->pRing = other.pRing; }
		const_iterator(base_iterator<const_iterator>&& other) { this->pCurr = std::move(other.pCurr); this->pRing = std::move(other.pRing); }
		const_iterator(iterator&& other) { this->pCurr = std::move(other.pCurr); this->pRing = std::move(other.pRing); }
		using base_iterator<const_iterator>::base_iterator;
		const Key& getKey() const { return this->pCurr->key; }
		const Info& getInfo() const { return this->pCurr->info; }
		const Info& operator*() const { return this->pCurr->info; }
	};
	
	BiRing(): pStart(nullptr), count(0) {}
	BiRing(const BiRing& src): BiRing() { this->append(src); }
	~BiRing() { this->clear(); }

	bool clear();
	[[nodiscard]] size_t size() const { return this->count; }
	[[nodiscard]] bool isEmpty() const { return !this->size(); }
	
	iterator begin() const;
	const_iterator cbegin() const { return this->begin(); }
	bool exist(const Key& key, const unsigned int occ = 1) const { return this->get(key, occ).isValid(); }

	const_iterator push(const Key& key, const Info& info);
	iterator get(const Key& key, unsigned int occ = 1) const;
	const_iterator cget(const Key& key, const unsigned int occ = 1) const { return this->get(key, occ); }

	iterator remove(iterator& target);
	iterator insert(iterator& target, const Key& key, const Info& info);
	const_iterator cremove(iterator& target) { return this->remove(target); }
	const_iterator cinsert(iterator& target, const Key& key, const Info& info) { return this->insert(target, key, info); }

	BiRing& operator=(const BiRing& src);
private:
	bool append(const BiRing& other);
};

#include "biRingImpl.tpp"
#include "biRingImplIterators.tpp"


#endif // SINGLY_LINKED_LIST_H
