#include <iostream>
using namespace std;

int main() {

	// Array bante time hi value de dena
	// int a[5] = {1, 2, 3, 4, 5};
	// We can skip mentioning number of buckets only during initialisation
	// All buckets that are not initialised will have value 0
	int a[20] = {};
	int n = sizeof(a) / sizeof(int);

	// cout << sizeof(a) << endl;

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}
















