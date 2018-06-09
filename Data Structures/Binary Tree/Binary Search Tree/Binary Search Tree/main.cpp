#include "Tree.h"

int main()
{
	Tree<int> tree;
	
	int size;
	std::cout << "Enter number of nodes : ";
	std::cin >> size;

	std::cout << "Enter data :\n";
	int data;
	for (int count = 0; count < size; ++count)
	{
		std::cin >> data;
		tree.push(data);
	}

	tree.print();

	return 0;
}