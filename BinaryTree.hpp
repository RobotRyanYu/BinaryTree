#pragma once
template<typename T>
struct node {

	node() {
		left_child = NULL;
		right_child = NULL;
	}

	T value;
	node<T> *left_child;
	node<T> *right_child;
};

template<typename T>
class BinaryTree {
private:
	node<T> *root;
	void Insert(T value, node<T> *leaf);
	node<T>* Search(T value, node<T> *leaf);
	void DestroyNode(node<T>* leaf);
public:

	BinaryTree();
	~BinaryTree();
	void Insert(T value);
	node<T>* Search(T value);
	void DestroyAll();
};

template<typename T>
BinaryTree<T>::BinaryTree() {
	root = NULL;
};

template<typename T>
BinaryTree<T>::~BinaryTree() {
	DestroyAll();
}

template<typename T>
void BinaryTree<T>::Insert(T value, node<T> *leaf) {

	if (value < leaf->value) {
		if (leaf->left_child == NULL) {
			leaf->left_child = new node<T>;
			leaf->left_child->value = value;
		}
		else
			Insert(value, leaf->left_child);
	}
	else if (value >= leaf->value) {
		if (leaf->right_child == NULL) {
			leaf->right_child = new node<T>;
			leaf->right_child->value = value;
		}
		else
			Insert(value, leaf->right_child);
	}

	return;
}

template<typename T>
void BinaryTree<T>::Insert(T value) {

	if (root == NULL) {
		root = new node<T>;
		root->value = value;
	}
	else {
		if (value < root->value) {
			if (root->left_child == NULL) {
				root->left_child = new node<T>;
				root->left_child->value = value;
			}
			else
				Insert(value, root->left_child);
		}
		else if (value >= root->value) {
			if (root->right_child == NULL) {
				root->right_child = new node<T>;
				root->right_child->value = value;
			}
			else
				Insert(value, root->right_child);
		}
	}

	return;
}

template<typename T>
node<T>* BinaryTree<T>::Search(T value, node<T>* leaf) {
	node<T>* result = NULL;

	if (leaf == NULL)
		return NULL;
	else {
		if (value == leaf->value)
			return leaf;
		else {
			if (value >= leaf->value) {
				result = Search(value, leaf->right_child);
			}
			else if (value < leaf->value) {
				result = Search(value, leaf->left_child);
			}
		}
	}

	return result;
}

template<typename T>
node<T>* BinaryTree<T>::Search(T value) {

	node<T>* result = NULL;

	if (root == NULL)
		return NULL;
	else {
		if (value == root->value)
			return root;
		else {
			if (value >= root->value) {
				result = Search(value, root->right_child);
			}
			else if (value < root->value) {
				result = Search(value, root->left_child);
			}
		}
	}

	return result;
}

template<typename T>
void BinaryTree<T>::DestroyAll() {

	if (root == NULL)
		return;
	else {
		DestroyNode(root);
	}

	return;
}

template<typename T>
void BinaryTree<T>::DestroyNode(node<T> *leaf) {
	
	if (leaf != NULL){
		DestroyNode(leaf->left_child);
		DestroyNode(leaf->right_child);
		delete leaf;
	}

	return;
}
