#include <iostream>
using namespace std;

int nstairs(int n, int k) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}

	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += nstairs(n - i, k);
	}

	return ans;
}

int main() {

	int n, k = 3;
	cin >> n;

	cout << nstairs(n, k) << endl;



	return 0;
}
















