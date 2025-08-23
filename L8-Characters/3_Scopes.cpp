#include <iostream>
using namespace std;

int a = 1000;

int main() {

	int a = 1;

	if (a > 0) {
		cout << a << endl;

		int a = 10;
		a = a + 1;

		cout << a << endl;
		// SCOPE RESOLUTION OPERATOR ::
		cout <<::a << endl; // global scope ka a
	}

	cout << a << endl;

	return 0;
}
















