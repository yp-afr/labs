#include <iostream>
using namespace std;

int func(int count, int from, int temp, int to)
{
	if (count == 0) return 0;

	func(count - 1, from, to, temp);
	cout << from << " => " << to << endl;
	func(count - 1, temp, from, to);
}

int main()
{
	int count = 0;
	cout << "Enter count: ";
	cin >> count;
	func(count, 1, 2, 3);

	return 0;
}