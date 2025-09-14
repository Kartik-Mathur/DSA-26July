#include <iostream>
using namespace std;

int main() {

	char ch = 'T';
	char *x = &ch;
	char **y = &x;

	cout << (int*)x << endl;
	cout << y << endl;

	// cout << (int)'A' << endl;


	// int a = 1;
	// int *ap = &a;

	// cout << &a << endl;
	// cout << ap << endl;

	return 0;
}
















