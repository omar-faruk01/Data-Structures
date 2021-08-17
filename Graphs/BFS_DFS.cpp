#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <queue>
#include <stack>
using namespace std; // So "std::cout" may be abbreviated to "cout"


void BFS(int G[][7], int start, int n)
{
	int i = start, j;
	queue<int> q;
	int visited[7] = { 0 };

	cout << i;
	visited[i] = 1;
	q.push(i);

	while (!q.empty())
	{
		i = q.front();
		q.pop();
		for (j = 1; j < n; j++)
		{
			if (G[i][j] ==1 && visited[j] == 0)
			{
				cout << j;
				visited[j] = 1;
				q.push(j);
			}
		}
	}
}

void DFS(int G[][7], int start, int n)
{
	static int visited[7] = { 0 };
	int j;

	if (visited[start] == 0)
	{
		cout << start;

		visited[start] = 1;
		for ( j = 1; j < n; j++)
		{
			if (G[start][j] == 1 && visited[j] ==0)
			{
				DFS(G, j, n);
			}
		}
	}
}

int main()
{
	int G[7][7] = {
		{0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0},
		{0,1,0,0,1,0,0},
		{0,1,0,0,1,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0}
	};

	cout << "BFS: ";
	BFS(G, 4, 7);
	cout << "\nDFS: ";
	DFS(G, 1, 7);

}
