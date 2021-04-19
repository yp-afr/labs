#pragma once
#include "includes.h"

class Array
{
private:
	int count;
	string* arr;
public:
	Array();

	bool addInTheArray(string data);
	bool deleteFromTheArray(int index);
	bool changeDataByIndex(string data, int index);
	string getDataByIndex(int index);
	int getCount();
	void showArray();
	void replace();
};