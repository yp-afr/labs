#include "array.h"

int Array::getCount()
{
	return count;
}

string Array::getDataByIndex(int index)
{
	return arr[index];
}

bool Array::changeDataByIndex(string data, int index)
{
	arr[index] = data;
	return 1;
}

bool Array::deleteFromTheArray(int index)
{
	try
	{

		string* tempArray = new string[count];
		for (int i = 0; i < count; i++)
		{
			tempArray[i] = arr[i];
		}

		delete[] arr;
		arr = new string[count - 1];

		for (int i = 0, j = 0; i < count; ++i, ++j)
			if (i != index)
			{
				arr[j] = tempArray[i];
			}
			else
				--j;
		--count;

		delete[] tempArray;

		return 1;
	}
	catch (...)
	{
		return 0;
	}
}

bool Array::addInTheArray(string data)
{
	try
	{
		string* tempArray = new string[count + 1];
		memcpy(tempArray, arr, count * sizeof(string));
		tempArray[count] = data;
		arr = tempArray;
		count++;
		return 1;
	}
	catch (...)
	{
		return 0;
	}

}


void Array::showArray()
{
	if (count == 0)
	{
		cout << "--------------\n";
		cout << "Пусто\n";
		cout << "--------------\n";
	}
	else
	{
		cout << "--------------\n";
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n--------------\n";
	}
}

Array::Array()
{
	count = 0;
	arr = new string[count];
}

void Array::replace()
{
	swap(arr[0], arr[count-1]);

	/*
	string temp = arr[0];
	arr[0] = arr[count-1];
	arr[count-1] = temp;
	*/
}