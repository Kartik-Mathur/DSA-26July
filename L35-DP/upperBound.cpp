#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	/*
		int a[] = {1, 2, 3, 4, 5};
		int n = sizeof(a) / sizeof(int);
		cout << upper_bound(a.begin(), a.end(), 6) << endl; // Address deta hai yeh
	*/
	vector<int> a({1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 7, 8, 9, 10});
	auto address = upper_bound(a.begin(), a.end(), 6);
	// auto address = lower_bound(a.begin(), a.end(), 6);

	int pos = (address - a.begin());
	if (address != a.end()) {
		cout << "Index : " << pos << endl; // Address deta hai yeh
	}





	return 0;
}
















