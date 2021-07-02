// show6.cpp

//--------------------------------------------------------------------

#include "StackArray.h"

template <typename DataType>
void StackArray<DataType>::showStructure() const

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
	if (isEmpty()) {
		cout << "Empty stack." << endl;
	}
	else {
		int j;
		cout << "Top = " << top << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j <= top; j++)
		{
			if (j == top)
			{
				cout << '[' << dataItems[j] << ']' << "\t"; // Identify top
			}
			else
			{
				cout << dataItems[j] << "\t";
			}
		}
		cout << endl;
	}
	cout << endl;
}

//--------------------------------------------------------------------
/*
template <typename DataType>
void StackLinked<DataType>::showStructure() const

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
	if (isEmpty())
	{
		cout << "Empty stack" << endl;
	}
	else
	{
		cout << "Top\t";
		for (StackNode* temp = top; temp != 0; temp = temp->next) {
			if (temp == top) {
				cout << "[" << temp->dataItem << "]\t";
			}
			else {
				cout << temp->dataItem << "\t";
			}
		}
		cout << "Bottom" << endl;
	}

}


*/

template<typename DataType>
inline StackArray<DataType>::StackArray(int maxNumber)
{
	maxSize=maxNumber;
	top = -1;
	dataItems = new DataType[maxSize];

}

template<typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
	maxSize = other.maxSize;
	top = other.top;
	dataItems = new StackArray[maxSize];
	for (int i = 0; i < top; i++)
	{
		this->dataItems[i] = other.dataItems[i];
	}

	return this->dataItems;
}

template<typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{
	// TODO: insert return statement here
	maxSize = other.maxSize;
	top = other.top;
	dataItems = new StackArray[maxSize];
	for (int i = 0; i < top; i++)
	{
		this->dataItems[i] = other.dataItems[i];
	}

	return *this;
}


template<typename DataType>
StackArray<DataType>::~StackArray()
{
	delete[] dataItems;
}

template<typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw(logic_error)
{
	if (isFull())
	{
		throw logic_error("Stack overflow!");
	}

	dataItems[++top] = newDataItem;
}

template<typename DataType>
DataType StackArray<DataType>::pop() throw(logic_error)
{
	if (isEmpty())
	{
		throw logic_error("Stack underflow!");
	}
	DataType x = dataItems[top];
	top -= 1;
	return x;
}

template<typename DataType>
void StackArray<DataType>::clear()
{
	top = -1;
}

template<typename DataType>
bool StackArray<DataType>::isEmpty() const
{
	if (top == -1)
	{
		return true;
	}
	return false;
}

template<typename DataType>
bool StackArray<DataType>::isFull() const
{
	if (top == maxSize-1)
	{
		return true;
	}
	return false;
}


