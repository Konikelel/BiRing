#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


template <typename Key, typename Info>
class bi_ring
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
public:
	class iterator
	{
	public:
		iterator() : pCurr(nullptr), pRing(nullptr) {}
		explicit iterator(Node* node, bi_ring* ring) : pCurr(node), pRing(ring) {}
		virtual ~iterator() = default; //TODO: maybe add reallocation

		virtual Key& getKey() const { return this->pCurr->key; }
		virtual Info& getInfo() const { return this->pCurr->info; }
		virtual Info& operator*() const { return this->pCurr->info; }

		virtual iterator& operator++();
		virtual iterator& operator--();
		virtual iterator operator++(int);
		virtual iterator operator--(int);
		virtual iterator operator+(int nr);
		virtual iterator operator-(int nr);
		virtual iterator& operator+=(int nr);
		virtual iterator& operator-=(int nr);
		virtual iterator& operator=(const iterator& other); //NOLINT

		[[nodiscard]] bool isValid() const { return this->pCurr != nullptr; }
		bool operator==(const iterator& other) const { return this->pCurr == other.pCurr; }
		bool operator!=(const iterator& other) const { return this->pCurr != other.pCurr; }
	protected:
		Node* pCurr;
		bi_ring* pRing;
		
		virtual iterator& move(bool forward);
		virtual iterator& move(iterator& obj, int nr);
		virtual iterator& move(int nr);
	};
	
	class const_iterator final : public iterator
	{
	public:
		explicit const_iterator(Node* node, bi_ring* ring) : iterator(node, ring) {}

		//TODO: check if other methods without const are accessible
		const Key& getKey() const override { return this->pCurr->key; }
		const Info& getInfo() const override { return this->pCurr->info; }
		const Info& operator*() const override { return this->pCurr->info; }
	};
	
	bi_ring(): pStart(nullptr), count(0) {}
	bi_ring(const bi_ring& src);
	~bi_ring();

	bool clear();
	[[nodiscard]] size_t size() const;
	[[nodiscard]] bool isEmpty() const;
	iterator& begin() const;
	const_iterator& cbegin() const;
	bool exist(const Key& key, unsigned int occ = 1) const;

	iterator& get(const Key& key, unsigned int occ = 1) const;
	const_iterator& cget(const Key& key, unsigned int occ = 1) const;
	bool get(const Key& key, iterator& result, unsigned int occ = 1) const;
	bool cget(const Key& key, const_iterator& result, unsigned int occ = 1) const;

	// const_iterator<Key, Info> pushBack(const Key& key, const Info& info);
	// const_iterator<Key, Info> pushFront(const Key& key, const Info& info);
	// iterator<Key, Info> popBack();
	// iterator<Key, Info> popFront();

	//TODO: Check if return iterator for popFront, popBack and erase
	//TODO: What if the position iterator belongs to another bi_ring?
	const_iterator insert(iterator& target, const Key& key, const Info& info);
	iterator remove(iterator& target);
	
	bi_ring& operator=(const bi_ring& src);

	template <typename K, typename I>
	friend std::ostream& operator<<(std::ostream& os, const bi_ring<K, I>& ring);
};

#include "bi_ring_impl_iterators.tpp"
#include "bi_ring_impl.tpp"


#endif // SINGLY_LINKED_LIST_H