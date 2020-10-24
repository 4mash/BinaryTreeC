#include <iostream>
#include "BinaryTree.h"
#include <random>
#include <ctime>

int main(void)
{
	srand(unsigned(time(nullptr)));
	BinaryTree *tree = new BinaryTree();
	tree->Add(5);
	tree->Add(1);
	tree->Add(3);
	tree->Add(2);
	tree->Add(8);
	tree->Add(-2);
	tree->Add(11);
	tree->Print(tree->getRoot(), 0);
	int key = 10;
	std::cout << "Tree size: " << tree->getSize() << std::endl;
	std::cout << "Key " << key << ((tree->Check(key)) ? " does exist" : " does not exist!");
	tree->Remove(1);
	tree->Print(tree->getRoot(), 0);
	return 0;
}