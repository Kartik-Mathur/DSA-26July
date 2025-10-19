#include <iostream>
using namespace std;

int update(int x) {
	return x + 1;
}

void increase(int &x) {
	x++;
}

int main() {


	int a = 1;
	a = update(a);

	cout << a << endl;

	increase(a);

	cout << a << endl;


	return 0;
}
















