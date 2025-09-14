#include <iostream>
using namespace std;

int main() {

	char a[100];
	cin.getline(a, 100, '@'); // default delimiter = '\n'


	cout << a << endl;

	// We can print array using loop too
	for (int i = 0; a[i] != '\0'; ++i)
	{
		cout << a[i] << "_";
	}

	return 0;
}
















