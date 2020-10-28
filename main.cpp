#include <iostream>
#include "BinaryTree.h"
#include <random>
#include <ctime>

int main(void)
{
	srand(unsigned(time(nullptr)));
	BinaryTree<int> *tree = new BinaryTree<int>();
	/*for (int i = 0; i < 10; i++)
	{
		tree->Add(rand() % 25);
	}*/
	tree->Insert(15);
	tree->Insert(10);
	tree->Insert(20);
	tree->Insert(8);
	tree->Insert(12);
	tree->Insert(18);
	tree->Insert(30);
	tree->Insert(19);
	tree->Insert(25);
	tree->Delete(20);
	tree->Print(tree->getRoot(), 0);
	tree->Empty();
	std::cout << "\nSize: " << tree->getSize() << std::endl;
	std::cout << "Key " << 12 << ((tree->Find(12)) ? " does exist" : " does not exist!");
	return 0;
}