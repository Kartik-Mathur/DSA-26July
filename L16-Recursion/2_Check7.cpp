#include <iostream>
using namespace std;

bool check7(int *a, int n) {
	if (n == 0) {
		return false;
	}

	if (a[0] == 7) {
		return true;
	}
	return check7(a + 1, n - 1);
	// bool smallContains7 = check7(a + 1, n - 1);
	// if (smallContains7 == true) {
	// 	return true;
	// }
	// else {
	// 	return false;
	// }
}

int main() {

	int a[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(a) / sizeof(int);

	if (check7(a, n)) {
		cout << "Present\n";
	}
	else {
		cout << "Not Present\n";
	}



	return 0;
}
















