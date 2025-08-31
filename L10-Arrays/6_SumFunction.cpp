#include <iostream>
using namespace std;

int add(int x, int y) {
	int ans = x + y;

	return ans;
}

int main() {

	int a = 5, b = 10;

	int sum = add(a, b);

	cout << "Sum : " << sum << endl;
	cout << "Sum : " << add(20, 30) << endl;


	return 0;
}
















