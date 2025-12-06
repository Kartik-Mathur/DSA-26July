#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> v = {1, 2, 4, 5, 6, 7, 8};

	for (int &d : v) {
		d++;
	}

	for (int d : v) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}
















