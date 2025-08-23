#include <iostream>
using namespace std;

int main() {

	int n = 127, cnt = 0;

	int i = 30;
	while (i >= 0) {

		if ((n & (1 << i)) > 0) {
			cnt++;
		}

		i--;
	}

	cout << cnt << endl;

	return 0;
}
















