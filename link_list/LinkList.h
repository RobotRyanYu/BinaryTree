#pragma once
template<typename T>
struct Node
{
	T data;
	Node<T> *next_node;
};

template<class T>
class LinkList
{
private:
	Node<T> *head_node, *tail_node;
public:
	LinkList()
	{
		head_node = tail_node = NULL;
	}

	void CreateNode(T value);
	void DisplayNode();
	void InsertStart(T value);
	void InsertEnd(T value);
	bool InsertPos(int pos, T value);
	bool DeleteStart();
	bool DeleteEnd();
	bool DeletePos(int pos);
	bool DeleteLink();
};