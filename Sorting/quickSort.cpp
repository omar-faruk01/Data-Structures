#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

int partition(int A[],int l, int h)
{
	int pivot = A[l];
	int i = l, j = h;
	int temp;

	do
	{
		do
		{
			i++;
		} while (A[i]<=pivot);
		do
		{
			j--;
		} while (A[i] > pivot);

		if (i<j) 
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	} while (i<j);

	temp = A[i];
	A[i] = A[j];
	A[j] = temp; 

	return j;
}

int quickSort(int A[], int l, int h)
{
	int j;

	if (l<h)
	{
		j = partition(A, l, h);
		quickSort(A, l, j);
		quickSort(A, j+1, h);
	}
}

int main()
{
	int A[] = { 10, 2, 19, 45, 89, 1, 3, 79, 36,24, INT32_MAX};
	int n = 11;

	quickSort(A, 0, 10);

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}

}