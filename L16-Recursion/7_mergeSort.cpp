#include <iostream>
using namespace std;

void merge(int *a, int *b, int *c, int s, int e) {
	int m = (s + e) / 2;
	int i = s, j = m + 1, k = s;

	while (i <= m and j <= e) {
		if (b[i] < c[j]) a[k++] = b[i++];
		else a[k++] = c[j++];
	}

	while (i <= m) {
		a[k++] = b[i++];
	}
	while (j <= e) {
		a[k++] = c[j++];
	}
}

void mergeSort(int *a, int s, int e) {
	if (s >= e) {
		return ;
	}
	// 1. Divide
	int mid = (s + e) / 2;
	int b[1000], c[1000];
	for (int i = s; i <= mid; ++i)
	{
		b[i] = a[i];
	}
	for (int i = mid + 1; i <= e; ++i)
	{
		c[i] = a[i];
	}
	// 2. Sort
	mergeSort(b, s, mid);
	mergeSort(c, mid + 1, e);
	// 3. Merge
	merge(a, b, c, s, e);
}

int main() {

	int a[] = {5, 4, 6, 3, 2, 1, 0};
	int n = sizeof(a) / sizeof(int);

	mergeSort(a, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}


	return 0;
}
















