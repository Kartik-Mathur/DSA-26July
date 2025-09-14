#include <iostream>
using namespace std;

void update(char *largest, char *a) {
	int lena = strlen(a);
	for (int i = 0; i <= lena; ++i)
	{
		largest[i] = a[i];
	}
}

int main() {

	char a[100], largest[100];
	int n, llen = 0;
	cin >> n;

	cin.ignore();

	for (int i = 0; i < n; ++i)
	{
		cin.getline(a, 100);
		int lena = strlen(a);

		if (lena > llen) {
			llen = lena;
			update(largest, a); // largest[] ke andar a[] ko daaldo
		}
	}

	cout << largest << endl;

	return 0;
}
















