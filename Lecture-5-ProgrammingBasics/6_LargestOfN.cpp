#include <iostream>
#include <climits> // INT_MIN: -2^31, INT_MAX: 2^31-1
using namespace std;

int main() {

	int n, i, no, ans = INT_MIN;

	cin >> n;

	i = 1;
	while (i <= n) {

		cin >> no;
		if (no > ans) {
			ans = no; // update karo if no aaya h jo that is bigger than ans
		}

		i = i + 1;
	}

	cout << "Largest : " << ans << endl;

	return 0;
}
















