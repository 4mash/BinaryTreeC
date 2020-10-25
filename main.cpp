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
	tree->Add(15);
	tree->Add(10);
	tree->Add(20);
	tree->Add(8);
	tree->Add(12);
	tree->Add(18);
	tree->Add(30);
	tree->Add(12);
	tree->Add(19);
	tree->Add(25);
	tree->Print(tree->getRoot(), 0);

	std::cout << "Size: " << tree->getSize() << std::endl;
	std::cout << "Key " << 12 << ((tree->Check(12)) ? " does exist" : " does not exist!");
//	tree->Empty();
	std::cout << "Size: " << tree->getSize() << std::endl;
	
	return 0;
}