#include "lab2.h"

void fillArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 654;
	}
}

void displayArray(int* arr, int n)
{
	char a;
	cout << "\n���������� ������? (y/n) ";
	cin >> a;
	if (a != 'y') return;
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

container methodOfChoice(int* arr, int n)
{
	chrono::duration<double> tm;
	int compare = 0;
	int swaps = 0;
	container _data;
	auto start = chrono::high_resolution_clock::now();

	for (int i = 0; i < n - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[min])
				min = j;
			compare++;
		}
		swap(arr[i], arr[min]);
		swaps++;
	}

	auto end = chrono::high_resolution_clock::now();

	tm = end - start;
	_data["Time"] = tm.count();
	_data["Compare"] = compare;
	_data["Swaps"] = swaps;

	return _data;
}

int increment(int *inc, long size) {
	int coef1, coef2, coef3, n;

	coef1 = coef2 = coef3 = 1;
	n = -1;
	do {
		if (++n % 2) {
			inc[n] = 8 * coef1 - 6 * coef2 + 1;
		}
		else {
			inc[n] = 9 * coef1 - 9 * coef3 + 1;
			coef2 *= 2;
			coef3 *= 2;
		}
		coef1 *= 2;
	} while (3 * inc[n] < size);

	return n > 0 ? --n : 0;
}



container methodOfShell(int* arr, int n)
{
	chrono::duration<double> tm;
	int compare = 0;
	int swaps = 0;
	container _data;
	long inc, i, j;
	int* d = new int[n];
	int size_d;
	auto start = chrono::high_resolution_clock::now();
	
	size_d = increment(d, n);
	while (size_d >= 0) {
		inc = d[size_d--];
		for (i = inc; i < n; i++) {
			int temp = arr[i];	
			for (j = i - inc; (j >= 0) && (arr[j] > temp); j -= inc)
			{
				arr[j + inc] = arr[j];
				compare++;
			}
			arr[j + inc] = temp;
			swaps++;
		}
	}

	auto end = chrono::high_resolution_clock::now();

	tm = end - start;
	_data["Time"] = tm.count();
	_data["Compare"] = compare;
	_data["Swaps"] = swaps;

	return _data;
}

void ConsoleLog(container results)
{
	cout << "\n����������: \n - ����� ������: " << to_string(results["Time"]) << " ������\n - ���������� ���������: " << (int)results["Compare"] << "\n - ���������� �������: " << (int)results["Swaps"] << endl;
}

void selectMethod(int* arr, int n)
{
	container results;

	int ans;
	cout << "\n\n�������� ����� ����������: " << "\n1. ������� ������" << "\n2. ������� �����" << "\n\n" << "> ";
	cin >> ans;

	switch (ans)
	{
	case 1:
		results = methodOfChoice(arr, n);
		ConsoleLog(results);
		break;
	case 2:
		results = methodOfShell(arr, n);
		ConsoleLog(results);
		break;
	default:
		break;
	}
}

