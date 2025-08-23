#include <iostream>
using namespace std;

int main() {

	// if i is prime then print it else ignore
	int i = 15, j;

	// i ko maan lia prime hai
	bool iPrimeHai = true;

	for (j = 2; j < i; ++j)
	{
		if (i % j == 0) { // agar i divide hua j se toh prime nhi h
			iPrimeHai = false;
		}
	}

	if (iPrimeHai) {
		cout << i << " ";
	}




	return 0;
}















