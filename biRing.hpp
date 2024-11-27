#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


template <typename Key, typename Info>
class biRing
{
	struct Node {
		Key key;
		Info info;
		Node* next;
		Node* prev;
		Node(const Key& key, const Info& info) : key(key), info(info), next(nullptr), prev(nullptr) {}
	};
	Node* pStart;
	size_t count;

	class baseIterator
	{
	public:
		baseIterator() : pCurr(nullptr), pRing(nullptr) {}
		baseIterator(Node* node, const biRing* ring) : pCurr(node), pRing(ring) {}
		virtual ~baseIterator() = default;

		virtual baseIterator& operator++();
		virtual baseIterator& operator--();
		virtual baseIterator operator++(int);
		virtual baseIterator operator--(int);
		virtual baseIterator operator+(int nr);
		virtual baseIterator operator-(int nr);
		virtual baseIterator& operator+=(int nr);
		virtual baseIterator& operator-=(int nr);
		baseIterator& operator=(const baseIterator& other);

		[[nodiscard]] bool isValid() const { return this->pCurr != nullptr; }
		bool operator==(const baseIterator& other) const { return this->pCurr == other.pCurr; }
		bool operator!=(const baseIterator& other) const { return this->pCurr != other.pCurr; }
		friend biRing;
	protected:
		Node* pCurr;
		const biRing* pRing;
		
		virtual baseIterator& move(bool forward);
		virtual baseIterator& move(baseIterator& obj, int nr);
		virtual baseIterator& move(int nr);
	};

	Node* remove(Node* target);
	Node* insert(Node* target, const Key& key, const Info& info);
public:
	class iterator final : public baseIterator
	{
	public:
		using baseIterator::baseIterator;
		using baseIterator::operator=;
		Key& getKey() const { return this->pCurr->key; }
		Info& getInfo() const { return this->pCurr->info; }
		Info& operator*() const { return this->pCurr->info; }
	};
	
	class constIterator final : public baseIterator
	{
	public:
		using baseIterator::baseIterator;
		using baseIterator::operator=;
		const Key& getKey() const { return this->pCurr->key; }
		const Info& getInfo() const { return this->pCurr->info; }
		const Info& operator*() const { return this->pCurr->info; }
	};
	
	biRing(): pStart(nullptr), count(0) {}
	biRing(const biRing& src);
	~biRing();

	bool clear();
	[[nodiscard]] size_t size() const;
	[[nodiscard]] bool isEmpty() const;
	iterator begin() const;
	constIterator cbegin() const;
	bool exist(const Key& key, unsigned int occ = 1) const;

	iterator get(const Key& key, unsigned int occ = 1) const;
	constIterator cget(const Key& key, unsigned int occ = 1) const;

	// constIterator<Key, Info> push(const Key& key, const Info& info);
	// iterator<Key, Info> pop();

	//TODO: Check if return iterator for popFront, popBack and erase
	//TODO: What if the position iterator belongs to another bi_ring?
	constIterator insert(baseIterator& target, const Key& key, const Info& info);
	constIterator remove(baseIterator& target);
	
	biRing& operator=(const biRing& src);

	template <typename K, typename I>
	friend std::ostream& operator<<(std::ostream& os, const biRing<K, I>& ring);
private:
	bool isForeignIter(const baseIterator& it) const;
};

#include "biRingImpl.tpp"
#include "biRingImplIterators.tpp"


#endif // SINGLY_LINKED_LIST_H
