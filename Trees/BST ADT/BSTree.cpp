
#include "BSTree.h"

template <typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode(const DataType& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr)
{
	root->dataItem = nodeDataItem;
	root->left = leftPtr;
	root->right = rightPtr;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree()
{
	root = NULL;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::BSTree(const BSTree<DataType, KeyType>& other)
{
	this = other;
	return *this;
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>:: operator= (const BSTree<DataType, KeyType>& other)
{
	if (this == &other)
	{
		return *this;
	}
	copyTree(other);
	return *this;
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::copyTree(const BSTree<DataType, KeyType>& otherTree)
{
	copyTreeHelper(root, otherTree->root);
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::copyTreeHelper(BSTreeNode*& p, const BSTreeNode* otherPtr)
{
	p->dataItem = otherTree->dataItem;
	p->left = copyTree(otherTree->left);
	p->right = copyTree(otherTree->right);
}

template < typename DataType, class KeyType >
BSTree<DataType, KeyType>::~BSTree()
{
	clear();
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::insert(const DataType& newDataItem)
{
	insertHelper(root, newDataItem);
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::insertHelper(BSTreeNode*& p, const DataType& newDataItem)
{
	if (p == 0)
	{
		p = new BSTree(newDataItem, 0, 0);
	}
	else if (newDataItem.getKey() < p->dataItem.getKey())
	{
		insertHelper(p->left, newDataItem);
	}
	else if (newDataItem.getKey() > p->dataItem.getKey())
	{
		insertHelper(p->right, newDataItem);
	}
	else
	{
		p->dataItem = newDataItem;
	}
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& searchDataItem) const
{
	return retrieveHelper(root, searchKey, searchDataItem);
}

template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::retrieveHelper(BSTreeNode* p, const KeyType& searchKey, DataType& searchDataItem) const
{
	if (p == NULL)
	{
		return false;
	}

	if (searchKey == p->dataItem.getKey())
	{
		return true;
	}
	else if (searchKey < p->dataItem.getKey())
	{
		retrieveHelper(root->left, searchKey, searchDataItem);
	}
	else
	{
		retrieveHelper(root->right, searchKey, searchDataItem);
	}
}


template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::remove(const KeyType& deleteKey)
{
	return removeHelper(root, deleteKey);
}

template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::removeHelper(BSTreeNode*& p, const KeyType& deleteKey)
{
	
	if (p == NULL)
	{
		return false;
	}
	else if (deleteKey < p->data)
	{
		p->left = removeHelper(p->left, deleteKey);
	}
	else if (deleteKey > p->data)
	{
		p->right = removeHelper(p->right, deleteKey);
	}
	else
	{
		if (p->left == NULL && p->right == NULL) // case 1 :  No Child
		{
			delete p;
			p = NULL;
			return true;
		}
		//Case 2: One Child
		else if (p->left == NULL)
		{
			BSTreeNode* temp = p;
			p = p->right;
			delete temp;
			return true;
		}
		else if (p->right == NULL)
		{
			BSTreeNode* temp = p;
			p = p->left;
			delete temp;
			return true;
		}
		else // case 3: two child
		{
			BSTreeNode* temp;
			if (p == NULL)
			{
				cout << "Error: Tree is empty\n";
				temp = NULL;
			}
			while (p->left != NULL)
			{
				temp = p->lchild;
			}
			p->data = temp->data;
			p->right = removeHelper(p->right, temp->data);
		}

	}
	return false;
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::cutRightmost(BSTreeNode*& r, BSTreeNode*& delPtr)
{
	// didnt need, used different method
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::writeKeys() const
{
	writeKeysHelper(root);
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeKeysHelper(BSTreeNode* p) const
{
	if (p != nullptr)
	{
		writeKeysHelper(p->left);
		cout << t->data << " ";
		writeKeysHelper(p->right);
	}
}

template < typename DataType, class KeyType >
void BSTree<DataType, KeyType>::clear()
{
	clearHelper(root);
}

template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::clearHelper(BSTreeNode* p)
{
	if (p)
	{
		clearHelper(p->left);
		clearHelper(p->right);
		delete p;
	}
}

template < typename DataType, class KeyType >
bool BSTree<DataType, KeyType>::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	return false;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getHeight() const
{
	return getHeightHelper(root);
}

template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getHeightHelper(BSTreeNode* p) const
{
	int x = 0, y = 0;

	if (p == 0)
	{
		return 0;
	}

	x = getHeightHelper(root->lchild);
	y = getHeightHelper(root->rchild);

	if (x > y)
	{
		return x + 1;
	}
	else
	{
		return y + 1;
	}
	return 0;
}

template < typename DataType, class KeyType >
int BSTree<DataType, KeyType>::getCount() const
{
	return getCountHelper(root);
}

template<typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getCountHelper(BSTreeNode* p) const
{
	int x, y;
	if (p != NULL)
	{
		x = getCountHelper(root->lchild);
		y = getCountHelper(root->rchild);
		return x + y + 1;
	}

	return 0;
}

//--------------------------------------------------------------------

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::showStructure() const

// Outputs the keys in a binary search tree. The tree is output
// rotated counterclockwise 90 degrees from its conventional
// orientation using a "reverse" inorder traversal. This operation is
// intended for testing and debugging purposes only.

{
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showHelper(root, 1);
		cout << endl;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::showHelper(BSTreeNode* p,
	int level) const

	// Recursive helper for showStructure. 
	// Outputs the subtree whose root node is pointed to by p. 
	// Parameter level is the level of this node within the tree.

{
	int j;   // Loop counter

	if (p != 0)
	{
		showHelper(p->right, level + 1);         // Output right subtree
		for (j = 0; j < level; j++)    // Tab over to level
			cout << "\t";
		cout << " " << p->dataItem.getKey();   // Output key
		if ((p->left != 0) &&           // Output "connector"
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showHelper(p->left, level + 1);          // Output left subtree
	}
}