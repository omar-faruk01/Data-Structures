#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

class Node {
public:
	int data;
	Node* next;
};

class HashTable {
public:
	Node** table;
	HashTable();
	int hash(int key);
	void Insert(int key);
	int Search(int key);
	~HashTable();
};


HashTable::HashTable()
{
	table = new Node * [10];
	for (int i = 0; i < 10; i++)
	{
		table[i] = nullptr;
	}
}

int HashTable::hash(int key)
{
	return key % 10;
}

void HashTable::Insert(int key)
{
	int index = hash(key);
	Node* t = new Node();
	t->data = key;
	t->next = nullptr;

	// If no nodes are in the linkedList
	if (table[index] == nullptr)
	{
		table[index] = t;
	}
	else
	{
		Node* p = table[index];
		Node* q = table[index];

		while (p && p->data < key)
		{
			q = p;
			p = p->next;
		}
		// if inserting at first
		if (q == table[index])
		{
			t->next = table[index];
			table[index] = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

int HashTable::Search(int key)
{
	int index = hash(key);
	Node* p = table[index];
	while (p)
	{
		if (p->data == key)
		{
			return p->data;
		}
		p = p->next;
	}
	return -1;
}

HashTable::~HashTable()
{
	for (int i = 0; i < 10; i++)
	{
		Node* p = table[i];
		while (table[i])
		{
			table[i] = table[i]->next;
			delete p;
			p = table[i];
		}
	}

	delete[] table;
}


int main()
{
	int A[] = { 16, 12, 25, 39, 6, 122, 5, 68, 75 };
	int n = sizeof(A) / sizeof(A[0]);
	HashTable H;
	for (int i = 0; i < n; i++) {
		H.Insert(A[i]);
	}
	cout << "Successful Search" << endl;
	int key = 6;
	int value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
}
