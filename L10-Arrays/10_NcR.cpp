#include <iostream>
using namespace std;

int fact(int n) {
	int ans = 1;
	for (int i = 1; i <= n; ++i)
	{
		ans *= i;
	}

	return ans;
}

int ncr(int n, int r) {
	int fn = fact(n);
	int fr = fact(r);
	int fnr = fact(n - r);

	int ans = fn / (fr * fnr);
	return ans;
}

int main() {

	int n, r;
	cin >> n >> r;

	cout << ncr(n, r) << endl;

	return 0;
}
















