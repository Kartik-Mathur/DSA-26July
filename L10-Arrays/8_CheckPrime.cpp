#include <iostream>
using namespace std;

bool isPrime(int n) {

	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0) {
			return false;
		}
	}

	// Loop se bahar aa gaye toh mtlb kisi se divide nhi hua thus it is prime
	return true;
}

int main() {

	int n;
	cin >> n;

	if (isPrime(n) == true) {
		cout << "Prime\n";
	}
	else {
		cout << "Not Prime\n";
	}

	return 0;
}
















