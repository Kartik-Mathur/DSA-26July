#include <iostream>
using namespace std;

int main() {

	int a = 1;
	cout << &a << endl;

	float f = 1.11;
	cout << &f << endl;

	cout << "sizeof(&a): " << sizeof(&a) << endl;
	cout << "sizeof(&f): " << sizeof(&f) << endl;

	return 0;
}
















