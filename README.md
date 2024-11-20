# Algorithm and Data Structure Task #2

## Part 1 - Design a `bi_ring` class

Design a class `bi_ring` to represent collection of bidirectionally linked elements containing Key and Info type values. Write unit tests for the designed class, at least one test per method.

Note that here implementation of iterators is mandatory. const_iterator does not allow for ring modification.
While thinking on class interface take into account four additional function templates declared below (with example results).
It should be possible to implement these functions effectively using your `bi_ring` template.

```c++
template <typename Key, typename Info>
class bi_ring	// implemented as doubly linked list
{
public:
	class iterator { /* … */ };
	class const_iterator { /* … */ };

	bi_ring();
	bi_ring(const bi_ring& src);
	~bi_ring();
	bi_ring& operator=(const bi_ring& src);

	iterator push_front(const Key& key, const Info& info);
	iterator pop_front();

	iterator insert(iterator position, …);
	iterator erase(iterator position);

	// what else can be useful in such a collection?
	// use examples of additional functions to guide you in the interface design
};
```

## Part 2 – Implement additional function templates
Write additional (external) function templates (not methods) paying attention to convenience of implementation.

```c++
// Filtering
// Resulting collection contains only the Key – Info pairs for which given predicate is true.
template<typename Key, typename Info>
bi_ring<Key, Info> filter(const bi_ring<Key, Info>& source, bool (pred)(const Key&));
```

### filter example:
#### Parameters:
    source => [uno:1, due:2, tre:3, quattro:4, cinque:5, sei:6, sette:7, otto:8]
    pred => [](const std::string& str) { return str.size() > 3; }

#### Result:
    result => [quattro:4, cinque:5, sette:7, otto:8]

```c++
// Joining
// Joins two rings summing Info if the same key is present in both rings
// (Info must have operator + defined)
// You can assume that in the input argumens keys are unique.
template<typename Key, typename Info>
bi_ring<Key, Info> join(const bi_ring<Key, Info>& first,
				const bi_ring<Key, Info>& second);
```

### join example:
#### Parameters:
    first => [uno:1, due:1, tre:2, quattro:1]
    second => [tre:1, due:1, quattro:3, cinque:5]

#### Result:
    result => [uno:1, due:2, tre:3, quattro:4, cinque:5]

```c++
// Unique
// Eliminates repetitions of the key value
// Resulting collection contains elemenst with unique keys.
// aggregate function is used to compute new info value for two elements with the same key.
template<typename Key, typename Info>
bi_ring<Key, Info> unique(const bi_ring<Key, Info>& source,
        Info(aggregate)(const Key&, const Info&, const Info&));
```

### unique example:
#### Parameters:
source => [one: uno, two : due, three : tre, one : eins, two : zwei,
		    three : drei, four : vier, five : cinque, six : sechs,
			seven : sieben, acht : otto, three : trzy, one : otto ]

aggregate =>
    unique<std::string, std::string>(src,
        [](const std::string&, const std::string& i1, const std::string& i2)
        {
            return i1 + "-" + i2;
        }
    );

#### Result:
    result =>  [ one : uno-eins-otto, two : due-zwei, three : tre-drei-trzy,
        four : vier, five : cinque, six : sechs, seven : sieben, acht : otto ]

```c++
// Shuffle
// Very strange join (shuffle) operation taking fcnt elements from the first bi_ring
// and scnt elements from the second bi_ring (repeated reps times)
// If we reach the end of the collection and need more elements,
// we start again from the beginning of the collection - cyclically
template<typename Key, typename Info>
bi_ring<Key, Info> shuffle(
	const bi_ring<Key, Info>& first, unsigned int fcnt,
	const bi_ring<Key, Info>& second, unsigned int scnt,
	unsigned int reps);
```

### unique example:
#### Parameters:
first => [uno:1, due:2, tre:3, quattro:4]
fcnt => 1
second => [bir:1, iki:2, uc:3, dort:4, bes:5]
scnt => 2
reps => 3

#### Result:
result => [uno:1, bir:1, iki:2, due:2, uc:3, dort:4, tre:3, bes:5, bir:1]


## Part 3 - During December 4th lab class
You'll be given specification of the function/template performing operation on `bi_ring` collection.
You'll have to implement this function and you'll have five minutes to present implementation of this function.
