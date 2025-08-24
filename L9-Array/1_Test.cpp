#include <iostream>
using namespace std;

int main() {

	int a[10000];

	int n;
	// cout << "Enter n(max->10000): ";
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		a[i] = i + 1;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}
















