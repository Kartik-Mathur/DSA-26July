#include <iostream>
using namespace std;

int main() {

	char a[100], b[100];

	cin.getline(a, 100);
	cin.getline(b, 100);

	int i = strlen(a);
	int j = 0;
	int lenb = strlen(b);

	while (j <= lenb) {
		a[i] = b[j];
		i++;
		j++;
	}


	cout << a << endl;

	return 0;
}
















