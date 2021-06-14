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

Node* rSearchTree(Node* t, int key)
{
	if (t == NULL)
	{
		return NULL;
	}

	if (key == t->data)
	{
		return t;
	}
	else if (key < t->data)
	{
		rSearchTree(t->lchild, key);
	}
	else
	{
		rSearchTree(t->rchild, key);
	}
}

Node* searchTree(Node* t, int key)
{

	while (t != NULL)
	{
		if (key == t->data)
		{
			return t;
		}

		if (key < t->data)
		{
			t = t->lchild;
		}
		else
		{
			t = t->rchild;
		}
	}

	return NULL;
	
}

Node* insert(Node* root, int key)
{
	Node* r, * p;

	if (root == NULL)
	{
		root = new Node();
		root->data = key;
		root->lchild = root->rchild = NULL;
	}
	else if (key <= root->data)
	{
		root->lchild = insert(root->lchild,key);
	}
	else
	{
		root->rchild = insert(root->rchild, key);
	}
	
	return root;
};

Node* findMin(Node* root)
{
	if (root == NULL)
	{
		cout << "Error: Tree is empty\n";
		return NULL;
	}
	while (root->lchild != NULL)
	{
		root = root->lchild;
	}
	return root;
}

Node* findMax(Node* root)
{
	if (root == NULL)
	{
		cout << "Error: Tree is empty\n";
		return NULL;
	}
	while (root->rchild != NULL)
	{
		root = root->rchild;
	}
	return root;
}

Node* Delete(Node* root, int key)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (key < root->data)
	{
		root->lchild = Delete(root->lchild, key);
	}
	else if (key > root->data)
	{
		root->rchild = Delete(root->rchild, key);
	}
	else
	{
		if (root->lchild == NULL && root->rchild == NULL) // case 1 :  No Child
		{
			delete root;
			root = NULL;
			return root;
		}
		//Case 2: One Child
		else if (root->lchild == NULL) 
		{
			Node* temp = root;
			root = root->rchild;
			delete temp;
			return root;
		}
		else if (root->rchild == NULL)
		{
			Node* temp = root;
			root = root->lchild;
			delete temp;
			return root;
		}
		else // case 3: two child
		{
			Node* temp = findMin(root->rchild);
			root->data = temp->data;
			root->rchild = Delete(root->rchild, temp->data);
		}

	}
}
void inOrder(Node* t) 
{
	if (t != nullptr)
	{
		inOrder(t->lchild);
		cout << t->data << " ";
		inOrder(t->rchild);
	}
}



int main() {
	Node* root = new Node();
	root = NULL;

	Node* t = new Node();

	root = insert(root, 5);
	root = insert(root,15);
	root = insert(root, 3);
	root = insert(root, 18);

	inOrder(root);

	t=searchTree(root, 3);
	if (t != NULL)
	{
		cout << endl << t->data << " is found!";
	}
	else
	{
		cout << t->data << " is not found!";
	}

	Delete(root, 3);
	t = searchTree(root, 3);
	if (t != NULL)
	{
		cout << endl << t->data << " is found!";
	}
	else
	{
		cout <<"Item is not found!";
	}
	

};