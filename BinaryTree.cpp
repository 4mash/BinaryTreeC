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
		root = new Node();
		root->key = value;
		size++;
		return true;
	}
	Node* n = root;
	while (n != nullptr)
	{
		if (value >= n->key)
		{
			if (n->right == nullptr)
			{
				n->right = new Node();
				n->right->key = value;
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
				n->left = new Node();
				n->left->key = value;
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
	Node* n = Check(value);
	if (n == nullptr) return false;
	Node* parent = n->parent;
	if (n->left == nullptr && n->right == nullptr)
	{
		if (parent->left == n) 
		{
			delete parent->left; 
			parent->left = nullptr;
		}
		else if (parent->right == n)
		{
			delete parent->right;
			parent->right = nullptr;
		}
	}
	else
	{
		Node* temp = n->right;
		while (temp->left)
		{
			temp = temp->left;
		}

		if (parent->left == n)
		{
			parent->left = temp;
			parent->left->left = n->left;
			parent->left->right = n->right;
			parent->left->parent = parent;
			delete n;
			delete temp;
		}
		else if (parent->right == n)
		{
			parent->right = temp;
			parent->right->left = n->left;
			parent->right->right = n->right;
			parent->right->parent = parent;
			delete n;
			if (temp->parent->left == temp)
			{
				delete temp->parent->left;
				temp->parent->left = nullptr;
			}
			else if (temp->parent->right == temp)
			{
				delete temp->parent->right;
				temp->parent->right = nullptr;
			}
		}
	}
	return true;
}

void BinaryTree::Print(Node *n, int spacing)
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

Node* BinaryTree::Check(int value)
{
	Node* n = root;
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

Node* BinaryTree::getRoot() const
{
	return root;
}

unsigned int BinaryTree::getSize() const
{
	return size;
}
