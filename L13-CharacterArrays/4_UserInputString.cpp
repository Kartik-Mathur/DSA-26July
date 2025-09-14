#include <iostream>
using namespace std;

void inputString(char a[], int n, char delimiter = '\n') {
	char ch;
	ch = cin.get();

	int i = 0;
	while (i < n - 1 && ch != delimiter) {
		a[i] = ch;
		i++;

		ch = cin.get();
	}
	a[i] = '\0';
}

int main() {

	char a[100];
	inputString(a, 100, '@');

	cout << a << endl;

	return 0;
}
















