#include <iostream>
using namespace std;

char a[][10] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

void intToString(int n) {
	if (n == 0) {
		return ;
	}

	int ld = n % 10;

	intToString(n / 10);
	cout << a[ld] << " ";
}

int main() {
	int n = 0;
	if (n == 0) {
		cout << "KUCH DAAL DE BHAI\n";
	}
	else {
		intToString(201);
	}


	return 0;
}
















