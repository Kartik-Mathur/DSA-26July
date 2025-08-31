#include <iostream>
using namespace std;

int main() {

	int a[] = {5, 3, 4, 1, 2}, j;
	int n = sizeof(a) / sizeof(int);

	for (int i = 1; i < n; ++i)
	{
		int hpc = a[i];

		for (j = i - 1; j >= 0 && hpc < a[j]; --j)
		{
			a[j + 1] = a[j];
		}

		a[j + 1] = hpc;
	}


	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;



	return 0;
}
















