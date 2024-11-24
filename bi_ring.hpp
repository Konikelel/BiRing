#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

template <typename Key, typename Info>
class iterator;
template <typename Key, typename Info>
class const_iterator;

template <typename Key, typename Info>
class bi_ring
{
public:
	bi_ring();
	bi_ring(const bi_ring& src);
	~bi_ring();

	bool exist(const Key& key, unsigned int occ = 1) const;
	const Info& getInfo(const Key& key, unsigned int occ = 1) const;
	bool getInfo(const Key& key, Info& result, unsigned int occ = 1) const;
	const_iterator<Key, Info> get(const Key& key, unsigned int occ = 1) const;
	bool get(const Key& key, const_iterator<Key, Info>& result, unsigned int occ = 1) const;
	
	[[nodiscard]] size_t size() const;
	[[nodiscard]] bool isEmpty() const;
	
	iterator<Key, Info> pushFront(const Key& key, const Info& info);
	iterator<Key, Info> pushBack(const Key& key, const Info& info);
	iterator<Key, Info> popFront();
	iterator<Key, Info> popBack();

	//TODO: What if the position iterator belongs to another bi_ring?
	iterator<Key, Info> insert(iterator position, const Key& key, const Info& info);
	iterator<Key, Info> erase(iterator position);

	
	bi_ring& operator=(const bi_ring& src);
	iterator<Key, Info> begin() const;
	
	friend iterator;
	friend const_iterator;
	friend std::ostream& operator<<(std::ostream& os, const bi_ring& ring);
private:
	struct Node {
		Key key;
		Info info;
		Node* next;
		Node* prev;
		Node(const Key& key, const Info& info) : key(key), info(info), next(nullptr), prev(nullptr) {}
	};

	Node* pStart;
	size_t count;
};


#endif // SINGLY_LINKED_LIST_H