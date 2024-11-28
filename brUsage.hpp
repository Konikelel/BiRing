#ifndef BR_USAGE_H
#define BR_USAGE_H


#include "biRing.hpp"

// Filtering
// Resulting collection contains only the Key – Info pairs for which given predicate is true.
template<typename Key, typename Info>
BiRing<Key, Info> filter(const BiRing<Key, Info>& source, bool (pred)(const Key&))
{
	auto result = BiRing<Key, Info>();
	for(auto nr = 0, it = source.cbegin(); nr < source.size(); ++nr, ++it)
	{
		if (pred(it.getKey()))
		{
			result.push(it.getKey(), it.getInfo());
		}
	}
	return result;
}


// Joining
// Joins two rings summing Info if the same key is present in both rings
// (Info must have operator + defined)
template<typename Key, typename Info>
BiRing<Key, Info> join(const BiRing<Key, Info>& first, const BiRing<Key, Info>& second)
{
	// auto result = BiRing<Key, Info>();
	// for(auto nr = 0, it = source.cbegin(); nr < source.size(); ++nr, ++it)
	// {
	// 	if (pred(it.getKey()))
	// 	{
	// 		result.push(it.getKey(), it.getInfo());
	// 	}
	// }
	// return result;
}


// Unique
// Eliminates repetitions of the key value
// Resulting collection contains elements with unique keys.
// aggregate function is used to compute new info value for two elements with the same key.
template<typename Key, typename Info>
BiRing<Key, Info> unique(const BiRing<Key, Info>& source, Info(aggregate)(const Key&, const Info&, const Info&));


// Shuffle
// Very strange join (shuffle) operation taking fcnt elements from the first bi_ring
// and scnt elements from the second bi_ring (repeated reps times)
// If we reach the end of the collection and need more elements,
// we start again from the beginning of the collection - cyclically
template<typename Key, typename Info>
BiRing<Key, Info> shuffle(const BiRing<Key, Info>& first, unsigned int fcnt, const BiRing<Key, Info>& second, unsigned int scnt, unsigned int reps);

#endif //BR_USAGE_H
