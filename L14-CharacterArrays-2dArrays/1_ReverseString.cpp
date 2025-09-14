#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char *a) {
	int i = 0;
	int j = strlen(a) - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i++;
		j--;
	}
}

int main() {

	char a[] = "hello";

	reverseString(a);

	cout << a << endl;

	return 0;
}
















