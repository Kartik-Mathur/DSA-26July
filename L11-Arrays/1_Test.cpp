#include <iostream>
using namespace std;

void print(int a[], int n) {

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	cout << endl;
}

void update(int a[], int n) {
	for (int i = 0; i < n; ++i)
	{
		a[i]++;
	}
}

int main() {

	int a[5] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);
	update(a, n);
	print(a, n);

	return 0;
}
















