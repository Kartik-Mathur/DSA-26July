#include <iostream>
using namespace std;

int main() {

	int *a = new int;
	*a = 1;
	cout << *a << endl;
	int n;
	// n = 30;
	cin >> n;

	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = i + 1;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}
















