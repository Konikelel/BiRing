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
	auto result = BiRing<Key, Info>();
	auto merged = BiRing<Key, Info>(first);
	merged.append(second);
	
	for(auto nr = 0, it = merged.cbegin(); nr < merged.size(); ++nr, ++it)
	{
		if (auto itTarget = result.get(it.getKey()); itTarget.isValid())
		{
			auto& infoTarget = itTarget.getInfo();
			infoTarget = infoTarget + it.getInfo();
		}
		else
		{
			result.push(it.getKey(), it.getInfo());
		}
	}
	return result;
}


// Unique
// Eliminates repetitions of the key value
// Resulting collection contains elements with unique keys.
// aggregate function is used to compute new info value for two elements with the same key.
template<typename Key, typename Info>
BiRing<Key, Info> unique(const BiRing<Key, Info>& source, Info(aggregate)(const Key&, const Info&, const Info&))
{
	auto result = BiRing<Key, Info>();
	for(auto nr = 0, it = source.cbegin(); nr < source.size(); ++nr, ++it)
	{
		if (auto itTarget = result.get(it.getKey()); itTarget.isValid())
		{
			auto& infoTarget = itTarget.getInfo();
			infoTarget = aggregate(it.getKey(), infoTarget, it.getInfo());
		}
		else
		{
			result.push(it.getKey(), it.getInfo());
		}
	}
	return result;
}


// Shuffle
// Very strange join (shuffle) operation taking fcnt elements from the first bi_ring
// and scnt elements from the second bi_ring (repeated reps times)
// If we reach the end of the collection and need more elements,
// we start again from the beginning of the collection - cyclically
template<typename Key, typename Info>
BiRing<Key, Info> shuffle(const BiRing<Key, Info>& first, unsigned int fcnt, const BiRing<Key, Info>& second, unsigned int scnt, unsigned int reps)
{
	auto result = BiRing<Key, Info>();
	auto itFirst = first.cbegin();
	auto itSecond = second.cbegin();
	for(unsigned int rep = 0; rep < reps; ++rep)
	{
		if (itFirst.isValid())
		{
			for(unsigned int nr = 0; nr < fcnt; ++nr, ++itFirst)
			{
				result.push(itFirst.getKey(), itFirst.getInfo());
			}
		}
		if(itSecond.isValid())
		{
			for(unsigned int nr = 0; nr < scnt; ++nr, ++itSecond)
			{
				result.push(itSecond.getKey(), itSecond.getInfo());
			}
		}
	}
	return result;
}

#endif //BR_USAGE_H
