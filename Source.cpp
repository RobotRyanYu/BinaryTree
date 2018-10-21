#include<iostream>

#include <iostream>
#include "BinaryTree.hpp"


int main() {

	BinaryTree<double> btree;

	btree.Insert(10);
	btree.Insert(5);
	btree.Insert(2);
	btree.Insert(7);

	node<double>* result = btree.Search(2);
	std::cout << result->value << std::endl;

	btree.DestroyAll();

	return 0;
}