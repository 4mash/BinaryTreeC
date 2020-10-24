#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	size = 0;
	root = nullptr;
}

bool BinaryTree::Add(int value)
{
	if (root == nullptr)
	{
		root = new BinaryTree::Node(value);
		size++;
		return true;
	}
	BinaryTree::Node* n = root;
	while (n != nullptr)
	{
		if (value >= n->key)
		{
			if (n->right == nullptr)
			{
				n->right = new BinaryTree::Node(value);
				n->right->parent = n;
				size++;
				break;
			}
			else n = n->right;
		}
		else if (value < n->key)
		{
			if (n->left == nullptr)
			{
				n->left = new BinaryTree::Node(value);
				n->left->parent = n;
				size++;
				break;
			}
			else n = n->left;
		}
	}
	return true;
}

bool BinaryTree::Remove(int value)
{
	BinaryTree::Node* n = Check(value);
	if (n == nullptr) return false;
	BinaryTree::Node* parent = n->parent;
	if (n->left == nullptr && n->right == nullptr)	//Deletion node has no children, is a leaf node.
	{
		if (n != root)
		{
			if (parent->left == n) parent->left = nullptr;
			else parent->right = nullptr;
			size--;
		}
		else
		{
			root = nullptr;
			size = 0;
		}
		delete n;
	}
	else if (n->right && n->left)	//Deletion node has two children.
	{
		BinaryTree::Node* successor = minimumKey(n->right);
		n->key = successor->key;
		if (successor->parent->left == successor)
		{
			if (successor->right)
				successor->parent->left = successor->right;
			else successor->parent->left = successor->left;
		}
		else
		{
			if (successor->right)
				successor->parent->right = successor->right;
			else successor->parent->right = successor->left;
		}	
		delete successor;
		size--;
	}
	else	//Deletion node has at least one child.
	{
		BinaryTree::Node* child = (n->left) ? n->left : n->right;
		if (n != root)
		{
			if (parent->left == n) parent->left = child;
			else parent->right = child;
			size--;
		}
		else root = child;
		delete n;
	}
	return true;
}

bool BinaryTree::Empty()
{

	return false;
}

void BinaryTree::Print(BinaryTree::Node *n, int spacing)
{
	if (n == nullptr)
		return;

	// Increase distance between levels  
	spacing += 10;

	// Process right child first  
	Print(n->right, spacing);

	// Print current node after space  
	// count  
	std::cout << std::endl;
	for (int i = 10; i < spacing; i++)
		std::cout << " ";
	std::cout << n->key << "\n";

	// Process left child  
	Print(n->left, spacing);
}

BinaryTree::Node* BinaryTree::Check(int value)
{
	BinaryTree::Node* n = root;
	while (n != nullptr)
	{
		if (value == n->key)
		{
			return n;
		}
		else
		{
			if (value > n->key && n->right != nullptr)
				n = n->right;
			else if (value < n->key && n->left != nullptr)
				n = n->left;
			else return nullptr;
		}
	}
}

BinaryTree::Node* BinaryTree::getRoot() const
{
	return root;
}

unsigned int BinaryTree::getSize() const
{
	return size;
}

BinaryTree::Node* BinaryTree::minimumKey(Node* n)
{
	while (n->left != nullptr)
		n = n->left;
	return n;
}
