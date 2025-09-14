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

	int key;
	cin >> key;
	bool keyFound = false;
	for (int i = 0; i < r; ++i)
	{

		for (int j = 0; j < c; ++j)
		{
			if (a[i][j] == key) {
				cout << "Key found " << i << ", " << j << endl;
				keyFound = true;
				break;
			}
		}

		if (keyFound) {
			break;
		}
	}

	if (keyFound == false) {
		cout << "Not found\n";
	}


	return 0;
}
















