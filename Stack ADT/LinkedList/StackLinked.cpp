// show6.cpp

//--------------------------------------------------------------------

#include "StackLinked.h"
#include <iostream>

using namespace std;


template<typename DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
{
	top = nullptr;
}

template<typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
	this = other;
	return *this;
}

template<typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
	if (this == &other)
	{
		return *this;
	}

	top = new StackNode(other.top->dataItem, 0);
	
	StackNode* thisTemp = 0, *thisPrevious = top;
	StackNode* p = other.top->next;

	while (p != nullptr)
	{
		thisTemp = new StackNode(p->dataItem, 0);
		thisPrevious->next = 0;
		thisPrevious = top->next;
		p = top;
	}
	return *this;
}

template<typename DataType>
StackLinked<DataType>::~StackLinked()
{
	clear();
	delete top;
}

template<typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw(logic_error)
{
	if (isFull())
	{
		throw logic_error("Stack overflow!");
	}
	top = new StackNode(newDataItem, top);
}

template<typename DataType>
DataType StackLinked<DataType>::pop() throw(logic_error)
{
	if (isEmpty())
	{
		throw logic_error("Stack underflow!");
	}

	StackNode* p = top;
	top = top->next;
	DataType x = p->dataItem;
	delete(p);
	return x;
}

template<typename DataType>
void StackLinked<DataType>::clear()
{
	StackNode* q;
	q = top;
	while (q != nullptr)
	{
		top = top->next;
		delete q;
		q = top;
	}

	if (q != nullptr)
	{
		delete q;
	}
}

template<typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
	if (top == nullptr)
	{
		return true;
	}
	return false;
}

template<typename DataType>
bool StackLinked<DataType>::isFull() const
{
	return false; // list can not be empty
}

//--------------------------------------------------------------------
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
