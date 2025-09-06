#include <iostream>
using namespace std;

void selectionSort(int a[], int n) {
	for (int i = 0; i < n - 1; ++i)
	{
		int mi = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[mi]) {
				mi = j;
			}
		}
		swap(a[i], a[mi]);
	}
}

void print(int a[], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	cout << endl;
}

int main() {

	int a[5] = {5, 3, 2, 1, 4};
	int n = sizeof(a) / sizeof(int);

	selectionSort(a, n);
	print(a, n);

	return 0;
}
















