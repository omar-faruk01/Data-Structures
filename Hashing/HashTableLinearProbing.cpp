#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

const int SIZE = 10;

int Hash(int key)
{
	return key % SIZE;
}

int probe(int H[], int key)
{
	int index = Hash(key);
	int i = 0;
	while (H[(index+i) % SIZE] != 0)
	{
		i++;
	}

	return (index + i) % SIZE;
}

void Insert(int H[], int key)
{
	int index = Hash(key);

	if (H[index] != 0)
	{
		index = probe(H, key);
	}
	H[index] = key;
}

int Search(int H[], int key)
{
	int index = Hash(key);
	int i = 0;

	while (H[(index + i) % SIZE] != key)
	{
		i++;
	}

	return (index + i) % SIZE;
}

int main()
{
	int HT[10] = { 0 };
	Insert(HT, 12);
	Insert(HT, 25);
	Insert(HT, 35);
	Insert(HT, 26);

	cout << "Key found at: " << Search(HT, 35);
}

