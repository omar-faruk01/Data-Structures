#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

void Insert(int A[], int n)
{
	int i = n, temp;
	temp = A[i];

	while (i>1 && temp>A[i/2])
	{
		A[i] = A[i / 2];
		i = i / 2;
	}
	A[i] = temp;
};

int Delete(int A[], int n)
{
	int i, j, x, temp, val;
	val = A[1];
	x = A[n];
	A[1] = A[n];

	A[n] = val;

	i = 1;
	j = i * 2;

	while (j<n-1)
	{
		if (A[j+1] > A[j])
		{
			j = j + 1;

		}

		if (A[i] < A[j])
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i = j;
			j = 2 * j;
		}
		else
		{
			break;
		}
	}

	return val;

};

void heapify(int A[], int n)
{
	for (int i = (n/2)-1; i >= 0; i--)
	{
		// # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
		int j = 2 * i + 1;  // Left child for current i

		while (j < n - 1) {
			// Compare left and right children of current i
			if (A[j] < A[j + 1]) {
				j = j + 1;
			}

			// Compare parent and largest child
			if (A[i] < A[j]) {
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				i = j;
				j = 2 * i + 1;
			}
			else {
				break;
			}
		}
	}
}

int main()
{
	int H[] = { 0,14,15,5,20,30,8,40 };
	int A[] = { 5,10,30,20,35,40,15 };

	// insert in heap
	for (int i=2; i <= 7; i++)
	{
		Insert(H, i);
	}

	// print heap
	for (int i = 1; i <= 7; i++)
	{
		cout << H[i] << " ";
	}

	heapify(A, sizeof(A) / sizeof(A[0]));
	cout << endl;
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	{
		cout << A[i] << " ";
	}

	cout << "\nDeleted value is: " << Delete(H, 3);
}