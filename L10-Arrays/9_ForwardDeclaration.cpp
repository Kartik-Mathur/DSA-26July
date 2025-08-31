#include <iostream>
using namespace std;
// Forward declaration
bool isPrime(int);
void printAllPrimes(int);


int main() {

	int n;
	cin >> n;
	printAllPrimes(n);

	return 0;
}


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

void printAllPrimes(int n) {

	for (int i = 2; i <= n; ++i)
	{
		if (isPrime(i)) {
			cout << i << " ";
		}
	}

	cout << endl;
}













