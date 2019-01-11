#include<iostream>
#include<stdlib.h>
#include "LinkList.h"
#include "LinkList.cpp"

using namespace std;

int main()
{
	int data[] = { 25, 50, 90, 40 };
	LinkList<int> link_list;
	for (int i = 0; i < 4; i++)
		link_list.CreateNode(data[i]);
	
	link_list.DisplayNode();
	link_list.DeleteLink();		link_list.DisplayNode();
	link_list.DeleteStart();	link_list.DisplayNode();
	link_list.DeleteEnd();		link_list.DisplayNode();
	link_list.DeletePos(10);	link_list.DisplayNode();
	link_list.InsertEnd(55);    link_list.DisplayNode();
	link_list.InsertStart(50);  link_list.DisplayNode();
	link_list.InsertPos(5, 60); link_list.DisplayNode();
	link_list.DeleteStart();	link_list.DisplayNode();
	link_list.DeleteStart();	link_list.DisplayNode();
	link_list.DeletePos(4);		link_list.DisplayNode();
	getchar(); getchar();
	return 0;
}