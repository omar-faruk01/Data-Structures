
#include "ListArray.h"

template < typename DataType >
List<DataType>::List ( int maxNumber ) : maxSize(maxNumber),
size(0), 
cursor(-1)
{
	dataItems = new DataType[maxSize];
}

template < typename DataType >
List<DataType>::List ( const List& source )
{
	maxSize = source.maxSize;
	cursor = source.cursor;
	size = source.size;
	dataItems = new DataType[maxSize];
	for (int i = 0; i < size; i++)
	{
		dataItems[i] = source.dataItems[i];
	}
}
    
template < typename DataType >
List<DataType>& List<DataType>::operator= ( const List& source )
{
	if (this != &source)
	{
		if (maxSize < source.maxSize)
		{
			delete[] dataItems;
			maxSize = source.maxSize;
			dataItems = new DataType[maxSize];
		}
		size = source.size;
		cursor = source.cursor;
		for (int i = 0; i < size; i++)
		{
			dataItems[i] = source.dataItems[i];
		}
	}
	return *this;
}

template < typename DataType >
List<DataType>::~List ()
{
	delete[] dataItems;
}

template < typename DataType >
void List<DataType>::insert ( const DataType& newDataItem )
	throw ( logic_error )
{
	if (this->isFull())
	{
		throw logic_error("Error: List is full!");
	}
	
	for (int i = size; i > cursor+1; i--)
	{
		dataItems[i] = dataItems[i - 1];
	}
	size++;
	cursor++;

	if (this->isEmpty())
	{
		dataItems[0] = newDataItem;
	}
	else
	{
		dataItems[cursor] = newDataItem;
	}
}

template < typename DataType >
void List<DataType>::remove () throw ( logic_error )
{
	if (this->isEmpty())
	{
		throw logic_error("Error: List is empty!");
	}

	for (int i = cursor; i < size - 1; i++)
	{
		dataItems[i] = dataItems[i+1];
	}
	size--;
	cursor--;
}

template < typename DataType >
void List<DataType>::replace ( const DataType& newDataItem )
	throw ( logic_error )
{
	if (this->isEmpty())
	{
		throw logic_error("Error: List is empty!");
	}
	
	dataItems[cursor] = newDataItem;
}

template < typename DataType >
void List<DataType>::clear ()
{
	size = 0;
	cursor = -1;
}

template < typename DataType >
bool List<DataType>::isEmpty () const
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

template < typename DataType >
bool List<DataType>::isFull () const
{
	if (size == maxSize)
	{
		return true;
	}
	return false;
}

template < typename DataType >
void List<DataType>::gotoBeginning ()
        throw ( logic_error )
{
	if (this->isEmpty())
	{
		throw logic_error("Error: List is empty!");
	}

	cursor = 0;
}

template < typename DataType >
void List<DataType>::gotoEnd ()
        throw ( logic_error )
{
	if (this->isEmpty())
	{
		throw logic_error("Error: List is empty!");
	}

	cursor = size-1;
}

template < typename DataType >
bool List<DataType>::gotoNext ()
        throw ( logic_error )
{
	if (this->isEmpty())
	{
		throw logic_error("Error: List is empty!");
	}
	if (cursor < size)
	{
		cursor = cursor + 1;
		return true;
	}
	else
	{
		return false;
	}
	
}

template < typename DataType >
bool List<DataType>::gotoPrior ()
        throw ( logic_error )
{
	if (this->isEmpty())
	{
		throw logic_error("Error: List is empty!");
	}
	if (cursor > 0)
	{
		cursor = cursor - 1;
		return true;
	}
	else
	{
		return false;
	}
}

template < typename DataType >
DataType List<DataType>::getCursor () const
        throw ( logic_error )
{
	DataType t;

	if (this->isEmpty())
	{
		throw logic_error("Error: List is empty!");
	}

	t = dataItems[cursor];
	return t;
}

#include "show3.cpp"

template < typename DataType >
void List<DataType>::moveToNth ( int n )
        throw ( logic_error )
{
	if (size < n+1)
	{
		throw logic_error("Error: List is too small!");
	}
	DataType value = getCursor();
	this->remove();
	cursor = n - 1;
	this->insert(value);
}

template < typename DataType >
bool List<DataType>::find ( const DataType& searchDataItem )
        throw ( logic_error )
{
	if (this->isEmpty())
	{
		throw logic_error("Error: List is empty!");
	}
	cursor = 0;
	for (int i = cursor; i < size; i++)
	{
		if (this->dataItems[i] == searchDataItem)
		{
			cursor = i;
			return true;
		}
	}

	return false;
}