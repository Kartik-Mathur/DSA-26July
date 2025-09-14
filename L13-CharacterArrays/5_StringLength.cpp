#include <iostream>
#include <cstring>
using namespace std;

int length(char a[]) {
	int i;
	for (i = 0; a[i] != '\0'; ++i)
	{

	}

	return i;
}

int main() {

	char a[100];
	cin.getline(a, 100);

	cout << length(a) << endl;
	cout << strlen(a) << endl;

	return 0;
}
















