#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

void selectionSort(int A[], int n)
{
	int k,i, j, temp;

	for (i = 0; i<n-1; i++)
	{
		k = i;
		for (j=i+1; j < n; j++)
		{
			if (A[j] < A[k])
			{
				k = j;
			}
		}
		temp = A[i];
		A[i] = A[k];
		A[k] = temp;
	}
}

int main()
{
	int A[] = { 10, 2, 19, 45, 89, 1, 3, 79 };
	int n = sizeof(A)/sizeof(A[0]);

	selectionSort(A, n);

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}

}