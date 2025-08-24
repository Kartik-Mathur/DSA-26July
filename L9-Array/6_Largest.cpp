#include <iostream>
#include <climits> // INT_MIN: -2^31
using namespace std;

int main() {
	/*
	int a[] = {0, 21, 13, 4, -5};
	int n = sizeof(a) / sizeof(int);
	*/
	int a[1000];
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	// Logic
	int ans = INT_MIN;

	int i = 0;
	while (i <= n - 1) {
		if (a[i] > ans) {
			ans = a[i];
		}

		i++;
	}
	cout << ans << endl;

	return 0;

}

