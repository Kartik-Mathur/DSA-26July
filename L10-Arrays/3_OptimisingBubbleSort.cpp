#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	for (int i = 0; i < n - 1; ++i)
	{
		bool swapHua = false;

		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (a[j] > a[j + 1]) {
				swapHua = true;
				swap(a[j], a[j + 1]);
			}
		}

		// Agar j ke loop ke bahar aakar dekha swapping nhi hui that means array
		// is sorted
		if (swapHua == false) {
			break; // i wale loop ko break kardo, no point of running algo further
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	return 0;
}
















