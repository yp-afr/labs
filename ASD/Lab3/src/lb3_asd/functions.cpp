#include "functions.h"

void checksBefore(List* list)
{
	system("cls");
	cout << "-- �������a ������ �� ����������������� --\n\n";
	cout << "���������� � ������ ������: " << (list->AddInTheBegin("first") ? "OK" : "������") << endl;
	cout << "���������� � ����� ������: " << (list->AddInTheEnd("last") ? "OK" : "������") << endl;
	cout << "���������� � ������� ������: " << (list->AddInTheMiddle("middle", 2) ? "OK" : "������") << endl;

	list->ShowList();

	cout << "�������� �� ������� ������: " << (list->DeleteFromTheMiddle(2) ? "OK" : "������") << endl;
	cout << "�������� � ����� ������: " << (list->DeleteFromTheEnd() ? "OK" : "������") << endl;
	cout << "�������� � ������ ������: " << (list->DeleteFromTheBegin() ? "OK" : "������") << endl;

	list->ShowList();

	system("pause");
}

void task(List* list)
{
	system("cls");
	cout << "������� ����� ����� ������, ��� ��������� ������� �����(����� ������) � ������� Enter: \n";
	string tempString;
	while (cin >> tempString && tempString != ".")
	{
		list->AddInTheEnd(tempString);
	}
	if (list->getCount() < 3)
	{
		cout << "��������� ������. ������� ������ 2 ����" << endl;
		return;
	}
	cout << "\n-- �������� ��������: \n";
	list->ShowList();
	Node* tempNode = new Node;
	tempNode = list->getHead();

	string headData = list->getHead()->data;
	string tailData = list->getTail()->data;

	while (headData == tailData)
	{
		list->DeleteFromTheEnd();
		tailData = list->getTail()->data;
	}
	string mainWord = list->getHead()->data;
	int n = list->getCount();
	for (int i = 0; i < n; i++)
	{
		Node* tempNodeHelper = tempNode->next;
		string compareWord = tempNode->data;
		if (mainWord == compareWord && tempNode != list->getHead())
		{
			tempNode->next->prev = tempNode->prev;
			tempNode->prev->next = tempNode->next;
			delete tempNode;
			list->decCount();
		}
		else {
			int sizeOfCompareWord = compareWord.size();
			if (sizeOfCompareWord % 2 == 0)
			{
				compareWord.insert(0, 1, compareWord[0]);
				tempNode->data = compareWord;
			}
			else if (sizeOfCompareWord % 2 == 1) {
				tempNode->data = compareWord.substr(0, compareWord.size() - 1);
			}
		}
		tempNode = tempNodeHelper;
	}

	cout << "\n-- ���������������� ���������: \n";
	list->ShowList();
	system("pause");
}

void list()
{
	List list;
	checksBefore(&list);
	task(&list);
}

void arr()
{
	system("cls");
	Array arr;
	string tempString;
	cout << "������� ����� ����� ������, ��� ��������� ������� �����(����� ������) � ������� Enter: \n";
	while (cin >> tempString && tempString != ".")
	{
		arr.addInTheArray(tempString);
	}
	cout << "\n-- �������� ��������: \n";
	arr.showArray();
	string mainWord = arr.getDataByIndex(0);
	for (int i = 0; i < arr.getCount(); i++)
	{
		string compareWord = arr.getDataByIndex(i);
		if (mainWord == compareWord && i != 0)
		{
			arr.deleteFromTheArray(i);
			--i;
		}
		else {
			int sizeOfCompareWord = compareWord.size();
			if (sizeOfCompareWord % 2 == 0)
			{
				compareWord.insert(0, 1, compareWord[0]);
				arr.changeDataByIndex(compareWord, i);
			}
			else if (sizeOfCompareWord % 2 == 1) {
				arr.changeDataByIndex(compareWord.substr(0, compareWord.size() - 1), i);
			}
		}
	}
	cout << "\n-- ���������������� ��������: \n";
	arr.showArray();
	cout << "\n-- Replace --\n";
	arr.replace();
	arr.showArray();
	system("pause");
}