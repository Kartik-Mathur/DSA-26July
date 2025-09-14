#include <iostream>
using namespace std;

bool findKey(int a[][100], int r, int c, int key) {

	for (int i = 0; i < r; ++i)
	{

		for (int j = 0; j < c; ++j)
		{
			if (a[i][j] == key) {
				cout << "Key found " << i << ", " << j << endl;
				return true;
			}
		}
	}

	return false;
}

void print(int a[][100], int r, int c) {
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {

	int a[100][100];
	int number = 1;
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			a[i][j] = number;
			number++;
		}
	}

	print(a, r, c);

	int key;
	cin >> key;

	if (findKey(a, r, c, key) == false) {
		cout << "Not found\n";
	}

	return 0;
}
















