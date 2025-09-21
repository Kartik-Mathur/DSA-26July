#include <iostream>
using namespace std;

int solve(int x, int n) {
	if (n == 0) {
		return 1;
	}

	return x * solve(x, n - 1);
}

int fastPower(int x, int n) {
	if (n == 0) {
		return 1;
	}

	int halfPower = fastPower(x, n / 2);
	if (n % 2 == 0) {
		return halfPower * halfPower;
	}
	else {
		return halfPower * halfPower * x;
	}
}

int main() {
	int a, n;
	cin >> a >> n;
	cout << fastPower(a, n) << endl;
	cout << solve(a, n) << endl;

	return 0;
}
















