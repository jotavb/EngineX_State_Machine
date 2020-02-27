#pragma once
#include <list>
#include <functional>
#include <assert.h>
#include "GameObject.h"

typedef unsigned int Hash;

template<class T, int SIZE>
class HashMap
{
public:

	HashMap()
	{
		assert(SIZE % 2 == 0); // Abort if it's not a power of two
		mMask = SIZE - 1;
	}

	bool Insert(T& data)
	{
		int desiredIndex = Translate(data->mHash);
		for (T& bucket_item : mBuckets[desiredIndex])
		{
			if (bucket_item->mHash == data->mHash)
			{
				return false;
			}
		}
		mBuckets[desiredIndex].push_back(data);
		return true;
	}

	void InsertNoCheck(T& data)
	{
		int index = Translate(data->mHash);
		mBuckets[index].push_back(data);
	}

	T Find(Hash hash)
	{
		int desiredIndex = Translate(hash);
		for (T& bucket_item : mBuckets[desiredIndex])
		{
			if (bucket_item->mHash == hash)
			{
				return bucket_item;
			}
		}
		return nullptr;
	}

	const T Find(Hash hash) const
	{
		int desiredIndex = Translate(hash);
		for (const T& bucket_item : mBuckets[desiredIndex])
		{
			if (bucket_item->mHash == hash)
			{
				return bucket_item;
			}
		}
		return nullptr;
	}

	void Delete(T data)
	{
		int desiredIndex = Translate(data->mHash);
		for (T& bucket_item : mBuckets[desiredIndex])
		{
			if (bucket_item->mHash == data->mHash)
			{
				mBuckets[desiredIndex].remove(bucket_item);
				break;
			}
		}
	}

private:

	int Translate(Hash hash) const
	{
		// The hash map mask with size of 256 the mask (0001 0000 0000) is going to be 255 (1111 1111)
		// If I want to store the hash 2568894 = 10 0111 0011 0010 1011 1110
		// Do an AND operation with the mask
		// The result is going to be 1011 1110 = index 190 inside the HashMap
		return (hash & mMask);
	}

private:

	Hash			mMask;

	std::list<T>	mBuckets[SIZE];
};