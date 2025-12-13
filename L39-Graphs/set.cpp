#include <iostream>
#include <set>
using namespace std;

int main() {

	set<int> s;

	s.insert(1);
	s.insert(4);
	s.insert(4);
	s.insert(4);
	s.insert(2);
	s.insert(3);

	for (auto e : s) {
		cout << e << " ";
	}
	cout << endl;

	while (!s.empty()) {
		cout << *(s.begin()) << endl;

		s.erase(s.begin());
	}

	return 0;
}

















