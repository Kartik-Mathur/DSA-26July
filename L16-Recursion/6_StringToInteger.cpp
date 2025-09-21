#include <iostream>
#include <cstring>
using namespace std;

int stringToInt(char *a, int n) {
	if (n == 0) {
		return 0;
	}

	int digit = a[n - 1] - '0';
	return stringToInt(a, n - 1) * 10 + digit;
}

int main() {

	char a[] = "1234";

	int x = stringToInt(a, strlen(a));

	cout << x << endl;

	return 0;
}
















