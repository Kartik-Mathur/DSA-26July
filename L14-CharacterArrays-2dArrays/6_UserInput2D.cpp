#include <iostream>
using namespace std;

int main() {

	int a[100][100];
	int number = 1;
	int r, c;
	cout << "Enter r and c : ";
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> number;
			a[i][j] = number;
		}
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}











