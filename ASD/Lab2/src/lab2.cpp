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
	cout << "\nОтобразить массив? (y/n) ";
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

container methodOfShell(int* arr, int n)
{
	chrono::duration<double> tm;
	int compare = 0;
	int swaps = 0;
	container _data;
	auto start = chrono::high_resolution_clock::now();

	for (int k = n / 2; k >= 1; k /= 2)
	{
		for (int i = k; i < n; i++)
		{
			for (int j = i; j >= k && arr[j - k] > arr[j]; j -= k)
			{
				swap(arr[j], arr[j - k]);
				swaps++;
				compare++;
			}
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
	cout << "\nРезультаты: \n - Время работы: " << to_string(results["Time"]) << " секунд\n - Количество сравнений: " << (int)results["Compare"] << "\n - Количество обменов: " << (int)results["Swaps"] << endl;
}

void selectMethod(int* arr, int n)
{
	container results;

	int ans;
	cout << "\n\nВыберите метод сортировки: " << "\n1. Методом выбора" << "\n2. Методом Шелла" << "\n\n" << "> ";
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