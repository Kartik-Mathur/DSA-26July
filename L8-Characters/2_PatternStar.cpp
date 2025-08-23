#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int r = 1; r <= n; ++r)
	{
		// 1. r times '*'
		for (int i = 0; i < r; ++i)
		{
			cout << '*';
		}
		// 2. ' '
		cout << ' ';
		// 3. n-r+1 times '*'
		for (int i = 0; i < n - r + 1; ++i)
		{
			cout << '*';
		}
		// 4. ' '
		cout << ' ';
		// 5. n-r+1 times '*'
		for (int i = 0; i < n - r + 1; ++i)
		{
			cout << '*';
		}
		// 6. ' '
		cout << ' ';
		// 7. r times '*'
		for (int i = 0; i < r; ++i)
		{
			cout << '*';
		}

		cout << endl;
	}


	return 0;
}
















