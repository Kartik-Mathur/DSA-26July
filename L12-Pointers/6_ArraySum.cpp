#include <iostream>
using namespace std;

int sumArray(int *a, int n) {
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += a[i];
	}
	return ans;
}

int main() {

	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	sumArray(a + 2, 5);

	return 0;
}
















