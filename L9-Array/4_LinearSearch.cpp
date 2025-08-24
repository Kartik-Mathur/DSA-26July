#include <iostream>
using namespace std;

int main() {
	int a[] = {1, 2, 3, 4, 5};
	int n = sizeof(a) / sizeof(int);

	int key;
	cin >> key; // Key is present or not?

	int ans = -1;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == key) {
			ans = i;
			break;
		}
	}

	if (ans == -1) cout << "Key not found\n";
	else cout << "Key found at: " << ans << endl;

	return 0;
}
















