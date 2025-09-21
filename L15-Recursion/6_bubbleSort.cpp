#include <iostream>
using namespace std;

void bubbleSort(int *a, int n, int i) {
	// base case
	if (i == n - 1) { // if i becomes n-1 that means we have placed n-1 elements at their correct pos
		return; // No need to sort any further...
	}

	// Ek element ko uski sahi jagah hum rakh dete hai
	for (int j = 0; j < n - 1 - i; ++j)
	{
		if (a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
		}
	}

	bubbleSort(a, n, i + 1); // Baaki ka kaam recursion ko bol diya to keep n-2 elements at correct place
}

void bubbleSort1(int *a, int n, int i, int j) {
	// base case
	if (i == n - 1) { // if i becomes n-1 that means we have placed n-1 elements at their correct pos
		return; // No need to sort any further...
	}

	// Ek element ko uski sahi jagah hum rakh dete hai
	if (j < n - 1 - i) {
		if (a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
		}
		bubbleSort1(a, n, i, j + 1);
	}
	else {
		bubbleSort1(a, n, i + 1, 0); // Baaki ka kaam recursion ko bol diya to keep n-2 elements at correct place
	}

}

int main() {
	int a[] = {5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);

	bubbleSort1(a, n, 0, 0);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	return 0;
}
















