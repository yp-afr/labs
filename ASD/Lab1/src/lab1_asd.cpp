#include <iostream>
using namespace std;


int counter = 0;

int func(int count, int from, int temp, int to)
{
	if (count == 0) return 0;

	func(count - 1, from, to, temp);
	cout << from << " => " << to << endl;
	counter++;
	func(count - 1, temp, from, to);
}

int main()
{
	int count = 0;
	cout << "Enter count: ";
	cin >> count;
	func(count, 1, 2, 3);
	cout << "Count: " << counter;
	return 0;
}