#include <iostream>
using namespace std;

int first7(int *a, int n, int i = 0) {
	if (i == n) {
		return -1; // Agar i n ke equal ho gaya means 7 present nhi hai poora array dekh lia
	}
	// Agar ith index par 7 hai toh mill gaya
	if (a[i] == 7) {
		return i;
	}
	// Chote array ka kaam recursion ko bol diya...
	int indx = first7(a, n, i + 1); // PURE ASSUMPTION
	return indx; // Ab agar index aaya toh vo return kardo, nahi milla toh -1 aaega vo hi return kro
}

int solve(int *a, int n) {
	if (n == 0) {
		return -1;
	}

	if (a[0] == 7) {
		return 0;
	}

	int indx = solve(a + 1, n - 1);
	if (indx == -1) {
		return -1;
	}
	else {
		return indx + 1;
	}
}

void printAll7(int *a, int n, int i) {
	if (i == n) {
		return;
	}

	if (a[i] == 7) {
		cout << i << " ";
	}
	printAll7(a, n, i + 1);
}

int main() {

	int a[] = {1, 2, 3, 7, 4, 5, 7};
	int n = sizeof(a) / sizeof(int);

	cout << first7(a, n) << endl;
	printAll7(a, n, 0);



	return 0;
}
















