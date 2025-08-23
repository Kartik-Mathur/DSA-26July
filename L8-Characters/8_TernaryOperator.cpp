#include <iostream>
using namespace std;

int main() {

	// Syntax: (condition) ? work : work ;
	int a = 1;

	a > 0 ? cout << "Hello\n" : cout << "World\n";
	cout << (a > 0 ?  "Hello\n" : "World\n");

	int x = (a > 0 ? 10 : -10); // Assigning values using ternary operator
	cout << x << endl;


	return 0;
}
















