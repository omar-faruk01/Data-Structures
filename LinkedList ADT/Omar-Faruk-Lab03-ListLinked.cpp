// Omar Faruk
//gw2625
//
//
#include "ListLinked.h"

// ListNode member functions

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr):dataItem(nodeData), next(nextPtr)
{
	this->dataItem = nodeData;
	this->next = nextPtr;
}

// List member functions

template <typename DataType>
List<DataType>::List(int ignored)
{
	ignored = 0;
	head = nullptr;
	cursor = nullptr;
}

template <typename DataType>
List<DataType>::List(const List& other) : head(0), cursor(0)
{
	ListNode* p;
	head = new ListNode<DataType>(0, nullptr);
	other.cursor = other.head;
	p = head->next;
	cursor = head;
	while (other.cursor != nullptr)
	{
		cursor->dataItem = other.cursor->dataItem;
		cursor->next = p;
		p = p->next;
		other.cursor = other.cursor->next;
	}

}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)
{
	if (this != &other)
	{
		clear();
	}
	ListNode* p;
	other.cursor = other.head;
	p = head->next;
	cursor = head;

	while (other.cursor != nullptr)
	{
		cursor->dataItem = other.cursor->dataItem;
		cursor->next = p;
		p = p->next;
		other.cursor = other.cursor->next;
	}
	
	return *this;
}

template <typename DataType>
List<DataType>::~List()
{
	clear();
	delete head;
	delete cursor;
}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)
{
	if (head == nullptr)
	{
		head = new ListNode(newDataItem, 0);
		cursor = head;
	}
	else
	{
		ListNode* p;
		p = new ListNode(newDataItem, 0);
		cursor->next = p;
		cursor = p;
	}
}

template <typename DataType>
void List<DataType>::remove() throw (logic_error)
{
	ListNode* p, *q;

	// if deleting first node
	if (cursor == head)
	{
		p = head;
		head = p->next;
		cursor = head;
		delete p;
	}
	else
	{
		// remove any nth node
		p = head->next;
		q = head;
		while (p != nullptr)
		{
			if (p == cursor)
			{
				q->next = p->next;
				if (!cursor)
				{
					cursor = head;
				}
				else
				{
					cursor = p->next;
				}
				delete p;
				break;
			}

			q = p;
			p = p->next;
		}
	}
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{
	if (isEmpty())
	{
		throw logic_error("ERROR: List is empty");
	}
	cursor->dataItem = newDataItem;
}

template <typename DataType>
void List<DataType>::clear()
{
	cursor = head;
	while (cursor != nullptr)
	{
		cursor = cursor->next;
		delete head;
		head = cursor;
	}
	
	if (cursor != nullptr)
	{
		delete cursor;
	}
}

template <typename DataType>
bool List<DataType>::isEmpty() const
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

template <typename DataType>
bool List<DataType>::isFull() const
{
	return false; // linked list can never be empty
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)
{
	if (!isEmpty())
	{
		cursor = head;
	}
	else
	{
		throw logic_error("ERROR: List is empty");
	}
	
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)
{

	if (!isEmpty())
	{
		while (cursor->next != nullptr)
		{
			cursor = cursor->next;
		}
	}
	else
	{
		throw logic_error("ERROR: List is empty");
	}
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
	if (cursor->next != nullptr)
	{
		cursor = cursor->next;
		return true;
	}
	return false;
}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)
{
	if (cursor != head)
	{
		ListNode* p;
		p = head;
		while (p->next != cursor)
		{
			p = p->next;
		}
		cursor = p;
		return true;
	}
	return false;
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)
{
	DataType t = NULL;
	if (!isEmpty())
	{
		t = cursor->dataItem;
	}
	return t;
}

template <typename DataType>
void List<DataType>::moveToBeginning() throw (logic_error)
{
	ListNode* p = new ListNode(cursor->dataItem, head);
	remove();
	cursor = p;
	head = p;
}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error)
{
	if (isEmpty())
	{
		insert(newDataItem);
	}
	else
	{
		ListNode* p;
		ListNode* q = head;
		p = new ListNode(cursor->dataItem, cursor->next);
		cursor->next = p;
		cursor->dataItem = newDataItem;
	}
}

#include "show5.cpp"

