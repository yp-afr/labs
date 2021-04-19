#pragma once
#include "includes.h"

struct Node
{
	string data;
	Node* next;
	Node* prev;
};

class List
{
private:
	int count;
	Node* head;
	Node* tail;
public:
	List();
	int getCount();
	void incCount();
	void decCount();
	bool AddInTheBegin(string data_);
	bool AddInTheEnd(string data_);
	bool AddInTheMiddle(string data_, int position);
	bool DeleteFromTheBegin();
	bool DeleteFromTheEnd();
	bool DeleteFromTheMiddle(int position);
	void ShowList();
	Node* getHead();
	Node* getTail();
	void setHead(Node* head_);
	void setTail(Node* tail_);
	void replace();
};