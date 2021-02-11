#include "lab2.h"

int main()
{
	srand(time(0));
	setlocale(0, "ru");
	int count = 0;
	cout << "Введите кол-во элементов массива: ";
	cin >> count;
	while (cin.fail() || count < 0)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("cls");
		cout << "Ошибка ввода! Попробуйте ещё раз\nВведите кол-во элементов массива: ";
		cin >> count;
	}
	
	int* array = new int[count];

	fillArray(array, count);
	displayArray(array, count);
	selectMethod(array, count);
	displayArray(array, count);

	delete[] array;
	return 0;
}
