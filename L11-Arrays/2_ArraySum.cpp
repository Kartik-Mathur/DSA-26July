#include <iostream>
using namespace std;

int sum(int a[], int n) {
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += a[i];
	}

	return ans;
}

int main() {

	int a[5] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);
	cout << sum(a, n) << endl;

	return 0;
}
















