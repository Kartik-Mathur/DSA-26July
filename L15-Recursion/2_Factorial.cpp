#include <iostream>
using namespace std;

// int fact(int n) {
// 	// base case
// 	if (n == 0) {
// 		return 1;
// 	}

// 	// recursive case: fact(n) = n * fact(n-1)
// 	int smaller = fact(n - 1); // PURE ASSUMPTION
// 	int bigger = n * smaller;
// 	return bigger;

// }

int fact(int n) {
	// base case
	if (n == 0) {
		return 1;
	}

	return n * fact(n - 1);

}

int main() {

	cout << fact(5) << endl;

	return 0;
}
















