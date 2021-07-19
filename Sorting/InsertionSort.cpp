#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

void insertionSort(int A[], int n)
{
	int j, x;

	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		x = A[i];
		while (A[j] > x && (j>-1))
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}

int main()
{
	int A[] = { 10, 2, 19, 45, 89, 1, 3, 79 };
	int n = 8;

	insertionSort(A, n);

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}

}