#include <iostream>
using namespace std;

void toh(int n, char src, char helper, char des) {
	if (n == 0) {
		return ;
	}

	// 1. Take n-1 disks from src to helper
	toh(n - 1, src, des, helper);
	// 2. Move nth disk from src to des
	cout << "Take disk " << n << " from " << src << " to " << des << endl;
	// 3. Take n-1 disks from helper to des
	toh(n - 1, helper, src, des);
}

int main() {
	int n;
	cin >> n;
	toh(n, 'A', 'B', 'C');

	return 0;
}
















