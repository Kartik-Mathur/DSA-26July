#include <iostream>
using namespace std;

int multiply(int a, int b) {
	if (b == 0) {
		return 0;
	}

	return a + multiply(a, b - 1);
}


int main() {

	int a = 5, b = 3;

	cout << multiply(a, b) << endl;


	return 0;
}
















