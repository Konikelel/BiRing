#include "bi_ring.h"

// Filtering
// Resulting collection contains only the Key – Info pairs for which given predicate is true.
template<typename Key, typename Info>
bi_ring<Key, Info> filter(const bi_ring<Key, Info>& source, bool (pred)(const Key&));


// Joining
// Joins two rings summing Info if the same key is present in both rings
// (Info must have operator + defined)
template<typename Key, typename Info>
bi_ring<Key, Info> join(const bi_ring<Key, Info>& first,
				const bi_ring<Key, Info>& second);


// Unique
// Eliminates repetitions of the key value
// Resulting collection contains elemenst with unique keys.
// aggregate function is used to compute new info value for two elements with the same key.
template<typename Key, typename Info>
bi_ring<Key, Info> unique(const bi_ring<Key, Info>& source,
Info(aggregate)(const Key&, const Info&, const Info&));


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
