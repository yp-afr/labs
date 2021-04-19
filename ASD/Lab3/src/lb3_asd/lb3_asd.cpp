#include "functions.h"

int main()
{
	setlocale(0, "ru");
	cout << "1. Динамический массив\n2. Список\n\n> ";
	char ans;
	cin >> ans;
	switch (ans)
	{
	case '1':
		arr();
		break;
	case '2':
		list();
		break;
	default:
		cout << "Ошибка ввода!";
		break;
	}
	return 0;
}

