#include <iostream>
using namespace std;

int main() {

	int a[] = {0, 21, 13, 4, -5};
	int n = sizeof(a) / sizeof(int);

	for (int i = n - 1; i >= 0; --i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
















