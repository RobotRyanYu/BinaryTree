#include "LinkList.h"

template<class T>
void LinkList<T>::CreateNode(T value)
{
	Node<T> * temp_node = new Node<T>;
	temp_node->data = value;
	temp_node->next_node = NULL;
	if (head_node == NULL)
	{
		head_node = tail_node = temp_node;
	}
	else
	{
		tail_node->next_node = temp_node;
		tail_node = temp_node;
	}
}

template<class T>
void LinkList<T>::DisplayNode()
{
	Node<T>* temp_node = head_node;
	while (temp_node != NULL)
	{
		std::cout << temp_node->data << '\t';
		temp_node = temp_node->next_node;
	}
	if (head_node != NULL)
		std::cout << std::endl;
	else
		std::cout << "this link list is empty" << std::endl;
}

template<class T>
void LinkList<T>::InsertStart(T value)
{
	Node<T>* temp_node = new Node<T>;
	temp_node->data = value;
	temp_node->next_node = head_node;

	if (head_node == NULL)
		head_node = tail_node = temp_node;
	else
		head_node = temp_node;
}

template<class T>
void LinkList<T>::InsertEnd(T value)
{
	Node<T>* temp_node = new Node<T>;
	temp_node->data = value;
	temp_node->next_node = NULL;

	if (head_node == NULL)
		head_node = tail_node = temp_node;
	else
	{
		tail_node->next_node = temp_node;
		tail_node = temp_node;
	}
}

template<class T>
bool LinkList<T>::InsertPos(int pos, T value)
{
	if (head_node == NULL || tail_node == NULL)
		return false;

	Node<T>* prev_node = new Node<T>;
	Node<T>* cur_node = new Node<T>;
	Node<T>* temp_node = new Node<T>;

	cur_node = head_node;
	for (int i = 1; i < pos; i++)
	{
		prev_node = cur_node;
		cur_node = cur_node->next_node;
		if (cur_node == NULL)
			return false;
	}

	temp_node->data = value;
	temp_node->next_node = cur_node;
	prev_node->next_node = temp_node;

	return true;
}

template<class T>
bool LinkList<T>::DeleteStart()
{
	if (head_node == NULL || tail_node == NULL)
		return false;
	Node<T>* temp_node = new Node<T>;
	if (head_node != tail_node)
	{
		temp_node = head_node;
		head_node = head_node->next_node;
		delete temp_node;
	}
	else
	{
		delete temp_node;
		head_node = tail_node = NULL;
	}
	return true;
}

template<class T>
bool LinkList<T>::DeleteEnd()
{
	if (head_node == NULL || tail_node == NULL)
		return false;
	Node<T>* prev_node = new Node<T>;
	Node<T>* cur_node = new Node<T>;;
	cur_node = head_node;
	while (cur_node->next_node != NULL)
	{
		prev_node = cur_node;
		cur_node = cur_node->next_node;
	}
	if (cur_node != head_node)
	{
		prev_node->next_node = NULL;
		tail_node = prev_node;
		delete cur_node;
	}
	else
	{
		delete cur_node;
		head_node = tail_node = NULL;
	}


	return true;
}

template<class T>
bool LinkList<T>::DeletePos(int pos)
{
	if (head_node == NULL || tail_node == NULL)
		return false;

	Node<T>* prev_node = new Node<T>;
	Node<T>* cur_node = new Node<T>;

	cur_node = head_node;
	for (int i = 1; i < pos; i++)
	{
		prev_node = cur_node;
		cur_node = cur_node->next_node;
		if (cur_node == NULL)
			return false;
	}

	prev_node->next_node = cur_node->next_node;
	delete cur_node;

	return true;
}

template<class T>
bool LinkList<T>::DeleteLink()
{
	if (head_node == NULL || tail_node == NULL)
		return false;

	Node<T>* temp_node = new Node<T>;
	temp_node = head_node;
	while (head_node != NULL)
	{
		temp_node = head_node;
		head_node = head_node->next_node;
		delete temp_node;
	}
	head_node = tail_node = NULL;
	return true;
}