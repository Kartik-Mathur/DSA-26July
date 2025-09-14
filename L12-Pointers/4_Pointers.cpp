#include <iostream>
using namespace std;


void update(int* &y) {
	*y = *y + 1;
	y = NULL;
}


int main() {

	// 1. Pointer ke through bucket ki value update karna: Call by reference.
	int a = 10;
	int *x = &a;
	update(x);

	cout << *x << endl;

	return 0;
}
















