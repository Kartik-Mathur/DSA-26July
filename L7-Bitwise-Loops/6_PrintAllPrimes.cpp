#include <iostream>
using namespace std;

int main() {

	int n, i, j;
	bool iPrimeHai;
	cin >> n;

	for (i = 2; i <= n; ++i)
	{
		// initially i ko maana prime hai
		iPrimeHai = true;

		for (j = 2; j < i; ++j)
		{
			if (i % j == 0) { // agar i divide hua j se toh prime nhi h
				iPrimeHai = false;
			}
		}
		// Check if prime hai toh print else skip
		if (iPrimeHai) {
			cout << i << " ";
		}

	}

	cout << endl;


	return 0;
}
















