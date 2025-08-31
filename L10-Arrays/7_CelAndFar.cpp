#include <iostream>
using namespace std;

void printTable(int init, int fval, int step) {
	int far, cel;
	far = init;
	while (far <= fval) {
		// cel = (5 / 9.0) * (far - 32);
		cel = (5) * (far - 32) / 9;

		cout << far << " : " << cel << endl;

		far = far + step;
	}
}


int main() {

	int init, fval, step, far, cel;
	cin >> init >> fval >> step;

	printTable(init, fval, step);
	printTable(0, 200, 30);


	return 0;
}
















