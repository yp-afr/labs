#include "list.h"

void List::setHead(Node* head_)
{
	head = head_;
}

void List::setTail(Node* tail_)
{
	tail = tail_;
}

Node* List::getHead()
{
	return head;
}

Node* List::getTail()
{
	return tail;
}
bool List::AddInTheBegin(string data_)
{
	try
	{
		Node* tempNode = new Node;
		tempNode->data = data_;
		tempNode->prev = NULL;
		if (head != NULL)
		{
			tempNode->next = head;
			head->prev = tempNode;
			head = tempNode;
		}
		else
		{
			tempNode->next = NULL;
			head = tail = tempNode;
		}
		incCount();
		return 1;
	}
	catch (...)
	{
		return 0;
	}
}

bool List::AddInTheEnd(string data_)
{
	try
	{
		Node* tempNode = new Node;
		tempNode->data = data_;
		tempNode->next = NULL;
		if (head != NULL)
		{
			tempNode->prev = tail;
			tail->next = tempNode;
			tail = tempNode;
		}
		else {
			tempNode->prev = NULL;
			head = tail = tempNode;
		}
		incCount();

	}
	catch (...)
	{
		return 0;
	}
}

bool List::AddInTheMiddle(string data_, int position)
{
	Node* tempNode = new Node;
	Node* tempNodeHelper = new Node;
	if (position <= 1 || position > count) return 0;
	if (count < 2 || head == NULL) return 0;

	try
	{
		tempNodeHelper = head;
		for (int i = 1; i < position; i++)
			tempNodeHelper = tempNodeHelper->next;
		tempNode->prev = tempNodeHelper->prev;
		tempNodeHelper->prev->next = tempNode;
		tempNodeHelper->prev = tempNode;
		tempNode->next = tempNodeHelper;
		tempNode->data = data_;

		incCount();

		return 1;
	}
	catch (...)
	{
		return 0;
	}

}

bool List::DeleteFromTheBegin()
{

	try
	{
		if (count == 0) return 0;
		if (count < 2)
		{

			if (head != NULL)
			{
				delete head;
				head = NULL;
				decCount();
			}
		}
		else
		{
			Node* tempNode = new Node;
			tempNode = head->next;
			head->next->prev = NULL;
			delete head;
			head = tempNode;
			decCount();
		}

		return 1;

	}
	catch (...)
	{
		return 0;
	}

}
bool List::DeleteFromTheEnd()
{

	try
	{
		if (count == 0) return 0;
		if (count < 2)
		{
			if (head != NULL)
			{
				delete head;
				head = NULL;
				decCount();
			}
		}
		else
		{
			Node* tempNode = new Node;
			tempNode = tail->prev;
			tail->prev->next = NULL;
			delete tail;
			tail = tempNode;
			decCount();
		}

		return 1;
	}
	catch (...)
	{
		return 0;
	}
}
bool List::DeleteFromTheMiddle(int position)
{

	try
	{

		if (position <= 1 || position >= count || count < 3) return 0;
		Node* tempNode = new Node;
		tempNode = head;
		for (int i = 1; i < position; i++)
			tempNode = tempNode->next;
		tempNode->next->prev = tempNode->prev;
		tempNode->prev->next = tempNode->next;

		delete tempNode;
		decCount();
		return 1;
	}
	catch (...)
	{
		return 0;
	}
}


void List::ShowList()
{
	if (count == 0)
	{
		cout << "--------------\n";
		cout << "Пусто\n";
		cout << "--------------\n";
	}
	else
	{
		Node* tempNode = new Node;
		tempNode = head;
		cout << "--------------\n";
		while (tempNode != NULL)
		{
			cout << tempNode->data << " ";
			tempNode = tempNode->next;
		}
		cout << "\n--------------\n";
	}

}

List::List()
{
	count = 0;
	head = NULL;
	tail = NULL;
}

int List::getCount()
{
	return count;
}

void List::incCount()
{
	count++;
}


void List::decCount()
{
	count--;
}

void List::replace()
{
	swap(head->data, tail->data);

	/*
	string temp = head->data;
	tail->data = head->data;
	head->data = temp;
	*/
}