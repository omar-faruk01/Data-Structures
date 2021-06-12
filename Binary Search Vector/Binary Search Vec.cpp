#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream> 
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <vector>
using namespace std;


int BinarySearch(vector<int> list, int key)
{
	int low, mid, high;
	low = 0;
	high = list.size();
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == list.at(mid))
		{
			return mid;
		}
		else if (key < list.at(mid))
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return -1;
}


int main()
{
	vector<int> list1;
	vector<int> list2;

	list1.push_back(2);
	list1.push_back(4);
	list1.push_back(6);
	list1.push_back(8);
	list1.push_back(10);

	list2.push_back(1);
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(7);
	list2.push_back(9);

	for (int i = 0; i < list1.size(); i++)
	{
		cout << list1[i] << ' ';
	}

	int index = BinarySearch(list1, 4);
	cout << endl << index;

}