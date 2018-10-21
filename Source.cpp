#include<iostream>

#include <iostream>
#include "BinaryTree.hpp"


int main() {

	BinaryTree<double> btree;

	btree.insert(10);
	btree.insert(5);
	btree.insert(2);
	btree.insert(7);

	node<double>* result = btree.search(2);
	std::cout << result->value << std::endl;

	return 0;
}