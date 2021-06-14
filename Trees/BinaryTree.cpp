#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <queue>
using namespace std; // So "std::cout" may be abbreviated to "cout"

class Node
{
public:
	Node* lchild;
	int data;
	Node* rchild;
};


Node* createTree()
{
	Node* newNode = new Node;
	int x;
	
	cout << "\nEnter value (-1 for no node): ";
	cin >> x;
	if (x == -1 )
	{
		return 0;
	}
	newNode->data = x;

	cout << "\nEnter left child of " << x;
	newNode->lchild = createTree();


	cout << "\nEnter right child of " << x;
	newNode->rchild= createTree();
	
	return newNode;
}

void preOrder(Node* t){
	if (t != nullptr)
	{
		cout << t->data << " ";
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}

void inOrder(Node* t) {
	if (t != nullptr)
	{
		inOrder(t->lchild);
		cout << t->data << " ";
		inOrder(t->rchild);
	}
}

void postOrder(Node* t)
{
	if (t != nullptr)
	{
		postOrder(t->lchild);
		postOrder(t->rchild);
		cout << t->data << " ";

	}
}

void levelOrder(Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> Q; // store and take place of node in queue

	while (!Q.empty())
	{
		Node* current = Q.front();
		cout << current->data << " ";
		if (current->lchild != NULL)
		{
			Q.push(current->lchild);
		}
		if (current->rchild != NULL)
		{
			Q.push(current->lchild);
		}
		Q.pop(); // remove element at front
	}
}

int countNodes(Node* root)
{
	int x, y;
	if (root!=NULL)
	{
		x = countNodes(root->lchild);
		y = countNodes(root->rchild);
		return x + y + 1;
	}
	
	return 0;
}

int findHeight(Node* root)
{
	int x=0, y=0;

	if (root == 0)
	{
		return 0;
	}

	x = findHeight(root->lchild);
	y = findHeight(root->rchild);

	if (x>y)
	{
		return x + 1;
	}
	else
	{
		return y + 1;
	}
	return 0;
}

int main()
{
	Node* root = createTree();
	preOrder(root);
	int count = countNodes(root);
	cout << "\nTotal Nodes: " << count;

}

