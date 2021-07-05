
#include "QueueLinked.h"

template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber)
{
	maxNumber = Queue<DataType>::MAX_QUEUE_SIZE;
}

template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other)
{
	QueueNode* cursor = front;
	QueueNode* p = front->next;
	QueueNode* q = other->front;

	while (q != NULL)
	{
		cursor->dataItem = q->dataItem;
		cursor->next = p;
		p = p->next;
		q = q->next;
	}

	back = cursor;
	return *this;
}

template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other)
{
	if (this == &other)
	{
		return *this;
	}

	QueueNode* cursor = front;
	QueueNode* p = front->next;
	QueueNode* q = other->front;

	while (q != NULL)
	{
		cursor->dataItem = q->dataItem;
		cursor->next = p;
		p = p->next;
		q = q->next;
	}

	back = cursor;
	return *this;
}

template <typename DataType>
QueueLinked<DataType>::~QueueLinked()
{
	clear();
	delete front;
	delete back;
}

template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
	if (isFull())
	{
		throw logic_error("Queue Overflow!");
	}
	QueueNode* t = new QueueNode(newDataItem,0);

	if (front == NULL)
	{
		front = back = t;
	}
	else
	{
		back->next = t;
		back = t;
	}
}

template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{
	if (isEmpty())
	{
		throw logic_error("Queue Underflow!");
	}

	DataType temp;
	temp = front->dataItem;

	QueueNode* p = front;
	front = front->next;
	delete p;

	return temp;
}

template <typename DataType>
void QueueLinked<DataType>::clear()
{
	QueueNode* p;
	p = front;
	while (p != nullptr)
	{
		p = p->next;
		delete front;
		front = p;
	}

	if (p != nullptr)
	{
		delete p;
	}
}

template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
{
	if (front == back)
	{
		return true;
	}
	return false;
}

template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
	return false; // can never be full unless heap is full
}

template <typename DataType>
void QueueLinked<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
	if (isEmpty())
	{
		throw logic_error("No elements in Queue!");
	}

	front->dataItem = newDataItem;
}

template <typename DataType>
DataType QueueLinked<DataType>::getRear() throw (logic_error)
{
	DataType temp;
	temp = back->dataItem;
	QueueNode* p = front;
	while (p != back)
	{
		p = p->next;
	}

	delete back;
	back = p;
	return temp;
}

template <typename DataType>
int QueueLinked<DataType>::getLength() const
{
	int x = 0;
	QueueNode* p = front;
	while (p != NULL)
	{
		x = x + 1;
		p = p->next;
	}

	return x;
}

template <typename DataType>
void QueueLinked<DataType>::showStructure() const
{
    QueueNode *p;   // Iterates through the queue

    if ( isEmpty() )
	cout << "Empty queue" << endl;
    else
    {
	cout << "Front\t";
	for ( p = front ; p != 0 ; p = p->next )
	{
	    if( p == front ) 
	    {
		cout << '[' << p->dataItem << "] ";
	    }
	    else
	    {
		cout << p->dataItem << " ";
	    }
	}
	cout << "\trear" << endl;
    }
}



