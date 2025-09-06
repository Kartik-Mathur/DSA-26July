#include <iostream>
using namespace std;

void mergeSorted(int a[], int n, int b[], int m) {
	int i = n - 1, j = m - 1, k = n + m - 1;

	while (i >= 0 and j >= 0) {
		if (a[i] > b[j]) {
			a[k--] = a[i--];
		}
		else {
			a[k--] = b[j--];
		}
	}

	// Agar j mei elements bach gaye toh add krdo a ke andar
	while (j >= 0) {
		a[k--] = b[j--];
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

	/*
	int a[100] = {3, 5, 7, 8, 9, 11};
	int n = 6;

	int b[4] = {1, 2, 4, 6};
	int m = sizeof(b) / sizeof(int);
	*/
	int a[1000], b[1000], n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}

	mergeSorted(a, n, b, m);
	print(a, n + m);


	return 0;
}
















