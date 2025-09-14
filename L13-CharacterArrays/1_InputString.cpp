#include <iostream>
using namespace std;

int main() {

	char a[100];
	cin >> a; // It will stop to read when space will come in between.....

	cout << a << endl;

	// We can print array using loop too
	for (int i = 0; a[i] != '\0'; ++i)
	{
		cout << a[i] << "_";
	}

	return 0;
}
















