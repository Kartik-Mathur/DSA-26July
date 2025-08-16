#include <iostream>
using namespace std;

int main() {

	int n; cin >> n;

	double ans = 0;
	double inc = 1;

	int cp = 1;
	while (cp <= 4) {

		// Har baari inc krna hai till ans*ans<=n
		while (ans * ans <= n) {

			ans = ans + inc;
		}
		ans = ans - inc;


		inc = inc / 10;
		cp = cp + 1;
	}

	cout << ans << endl;
	return 0;
}
















