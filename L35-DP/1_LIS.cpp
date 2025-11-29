#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int a[] = {10, 9, 3, 5, 4, 11, 7, 8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
	int n = sizeof(a) / sizeof(int);

	vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		if (v.size() == 0 or a[i] > v.back()) {
			v.push_back(a[i]);
		}
		else {
			int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			v[pos] = a[i];
		}
	}

	cout << "LIS: " << v.size() << endl;

	return 0;
}
















