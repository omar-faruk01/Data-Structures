#include <iostream>
#include "HashTable.h"

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize)
{
	tableSize = initTableSize;
	dataTable = new BSTree<DataType, KeyType>[tableSize];
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& other)
{
	copyTable(other);
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>& HashTable<DataType, KeyType>::operator=(const HashTable& other)
{
	if (this != &other)
	{
		clear();
		copyTable(other);
		return *this;
	}
	else
	{
		return *this;
	}
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source)
{
	tableSize = source.tableSize;
	dataTable = new BSTree<DataType, KeyType>[tableSize];
	for (int i = 0; i < tableSize; i++)
	{
		dataTable[i] = source.dataTable[i];
	}
}

template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable()
{
	delete[] dataTable;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem)
{
	unsigned int loc = DataType::hash(newDataItem.getKey()) % tableSize;
	dataTable[loc].insert(newDataItem);
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey)
{
	unsigned int key = DataType::hash(deleteKey) % tableSize;

	bool valid = dataTable[key].remove(deleteKey);
	return valid;
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const
{
	unsigned int key = DataType::hash(searchKey) % tableSize;

	bool valid = dataTable[key].retrieve(searchKey, returnItem);
	return valid;
}

template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear()
{
	for (int i = 0; i < tableSize; i++)
	{
		dataTable[i].clear();
	}
}

template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const
{
	for (int i = 0; i < tableSize; i++)
	{
		if (!dataTable[i].isEmpty())
		{
			return false;
		}
	}

	return true;
}



template <typename DataType, typename KeyType>
double HashTable<DataType, KeyType>::standardDeviation() const
{
	int count = 0;
	for (int i = 0; i < tableSize; i++)
	{
		count = count + dataTable[i].getCount();
	}
	
	double avg = count / tableSize;
	double total = 0;

	for (int i = 0; i < tableSize; i++)
	{
		int length =  dataTable[i].getCount();
	}

	double avg = count / tableSize;
	double total = 0;

	for (int i = 0; i < tableSize; i++)
	{
		int length = dataTable[i].getCount();
		total = total + (length - avg) * (length - avg);
	}

	return sqrt(total / (tableSize - 1));
}


template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const {
	for (int i = 0; i < tableSize; i++)
	{
		cout << i << ": ";
		dataTable[i].writeKeys();
	}
}
