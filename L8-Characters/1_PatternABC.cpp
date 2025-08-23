#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	for (int r = 1; r <= n; ++r)
	{
		// Increasing character
		char c = 'A';
		for (int i = 0; i < n - r + 1; ++i)
		{
			cout << c << ' ';
			c++;
		}

		c--; // Ek baari character peeche kardo to find starting of dec characters

		// Decreasing characters print
		for (int i = 0; i < n - r + 1; ++i)
		{
			cout << c << ' ';
			c--;
		}


		cout << endl;
	}

	return 0;
}
















