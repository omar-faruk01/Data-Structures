
#include "QueueArray.h"

template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)
{
    maxSize = maxNumber;
    front = 0;
    back = 0;
    dataItems = new DataType[maxSize];
}

template <typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other)
{
    this = other;
    return *this;
}

template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray& other)
{
    if (this->back != other->back)
    {
        clear();
    }


    front = other.front;
    back = other.back;
    maxSize = other.maxSize;

    for (int i = 0; i < other.back; i++)
    {
        dataItems[i] = other.dataItems[i];
    }

    return *this;
}

template <typename DataType>
QueueArray<DataType>::~QueueArray()
{
    delete[] dataItems;
}


template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
    if (isFull())
    {
        throw logic_error("Queue overflow!");
    }
    back = (++back) % maxSize;
    dataItems[back] = newDataItem;
    
}

template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error)
{
    if (isEmpty())
    {
        throw logic_error("Queue underflow!");
    }

	DataType temp;
    front = (front + 1) % maxSize;
    temp = dataItems[front];
	return temp;
}

template <typename DataType>
void QueueArray<DataType>::clear()
{
    front = 0;
    back = 0;
}

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const
{
    if (front == back)
    {
        return true;
    }
    return false;
}

template <typename DataType>
bool QueueArray<DataType>::isFull() const
{
    if (front == ((back+1) % maxSize))
    {
        return true;
    }
    return false;
}

template <typename DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{
    dataItems[front] = newDataItem;
   
}

template <typename DataType>
DataType QueueArray<DataType>::getRear() throw (logic_error)
{
	DataType temp;
    temp = dataItems[back];
    back = (back - 1 % maxSize);
	return temp;
}

template <typename DataType>
int QueueArray<DataType>::getLength() const
{
    if (isEmpty())
    {
        return 0;
    }
    else if (front < back)
    {
        return (back - front)+1;
    }
    else
    {
        return (maxSize - front) + (back + 1);

    }
}

//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::showStructure() const 
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1 )
       cout << "Empty queue" << endl;
    else
    {
       cout << "Front = " << front << "  Back = " << back << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       if ( back >= front )
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) && ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       else
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) || ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       cout << endl;
    }
}