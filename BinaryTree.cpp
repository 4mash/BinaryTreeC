#include "BinaryTree.h"

template<typename T>
BinaryTree<T>::BinaryTree()
{
	size = 0;
	root = nullptr;
}

template<typename T>
bool BinaryTree<T>::Add(T value)
{
	if (root == nullptr)
	{
		root = new BinaryTree<T>::Node(value);
		size++;
		return true;
	}
	BinaryTree<T>::Node* n = root;
	while (n != nullptr)
	{
		if (value >= n->key)
		{
			if (n->right == nullptr)
			{
				n->right = new BinaryTree<T>::Node(value);
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
				n->left = new BinaryTree<T>::Node(value);
				n->left->parent = n;
				size++;
				break;
			}
			else n = n->left;
		}
	}
	return true;
}

template<typename T>
bool BinaryTree<T>::Remove(T value)
{
	BinaryTree<T>::Node* n = Check(value);
	if (n == nullptr) return false;
	BinaryTree<T>::Node* parent = n->parent;
	if (n->left == nullptr && n->right == nullptr)	//Node to be deleted has no children, is a leaf node.
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
		BinaryTree<T>::Node* successor = minimumKey(n->right);
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
		BinaryTree<T>::Node* child = (n->left) ? n->left : n->right;
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

template<typename T>
bool BinaryTree<T>::Empty()
{
	if (root == nullptr) return false;
	if (root->left == nullptr && root->right == nullptr)
	{
		delete root;
		root = nullptr;
		size = 0;
		return true;
	}
	BinaryTree<T>::Node* n = leafNode(true);

	while (n != nullptr)
	{
		if (n->left)
		{
			n = n->left;
		}
		else if (n->right)
		{
			n = n->right;
		}
		else if (n->left == nullptr && n->right == nullptr)
		{
			if (n->parent)
			{
				if (n->parent->left == n)
				{
					delete n->parent->left;
					n->parent->left = nullptr;
				}
				else if (n->parent->right == n)
				{
					delete n->parent->right;
					n->parent->right = nullptr;
				}
			}
			n = n->parent;
			size--;
		}
	}
	return true;
}

template<typename T>
unsigned int BinaryTree<T>::Count(T value)
{
	int count = 0;
	BinaryTree<T>::Node* n = root;
	while (n != nullptr)
	{
		if (n->key == value)
			count++;
		if (value < n->key)
			n = n->left;
		else if (value >= n->key)
			n = n->right;
		
	}
	return count;
}

template<typename T>
void BinaryTree<T>::Print(BinaryTree<T>::Node *n, int spacing)
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

template<typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::Check(T value)
{
	BinaryTree<T>::Node* n = root;
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
	return n;
}

template<typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::getRoot() const
{
	return root;
}

template<typename T>
unsigned int BinaryTree<T>::getSize() const
{
	return size;
}

template<typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::minimumKey(Node* n)
{
	while (n->left != nullptr)
		n = n->left;
	return n;
}

template<typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::leafNode(bool left)
{
	BinaryTree<T>::Node* n = root;
	if (left)
	{
		while (n->left != nullptr)
			n = n->left;
	}
	else
	{
		while (n->right != nullptr)
			n = n->right;
	}

	return n;
}
