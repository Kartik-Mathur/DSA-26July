#include <iostream>
using namespace std;

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

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	// wave print
	for (int j = 0; j < c; ++j)
	{
		if (j % 2 == 0) {
			for (int i = 0; i < r; ++i)
			{
				cout << a[i][j] << " ";
			}
		}
		else {
			for (int i = r - 1; i >= 0; --i)
			{
				cout << a[i][j] << " ";
			}
		}
	}

	return 0;
}
















