#include <iostream>
using namespace std;

void rotateString(char *a, int k) {
	int len = strlen(a);
	k %= len;

	int i = len - 1;
	while (i >= 0) {
		a[i + k] = a[i];
		i--;
	}

	i = 0;
	int j = len;
	while (i < k) {
		a[i] = a[j];
		i++;
		j++;
	}

	a[len] = '\0';
}

void reverse(char *a, int i, int j) {
	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
}

void rotateString1(char *a, int k) {
	int len = strlen(a);
	k %= len;
	reverse(a, 0, len - 1);
	reverse(a, 0, k - 1);
	reverse(a, k, len - 1);
}

int main() {

	char a[] = "Coding";
	int k = 4123124;

	rotateString1(a, k);

	cout << a << endl;
	return 0;
}
















