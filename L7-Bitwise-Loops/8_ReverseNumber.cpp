#include <iostream>
using namespace std;

int main() {

	int n, d, ans = 0;

	for (cin >> n; n > 0; n /= 10) {
		d = n % 10;
		ans = ans * 10 + d;
	}

	cout << ans << endl;

	return 0;
}
















