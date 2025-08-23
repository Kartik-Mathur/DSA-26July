cout << a << endl;
#include <iostream>
using namespace std;

int main() {

	char ch;
	int cnt = 0;
	// cin ignores whitespace characters : [ ' ', '\n', '\t' ]
	cin >> ch; // Init
	while (ch != '$') { // Condition check
		cnt++;

		cin >> ch; // Updation of ch bucket
	}

	cout << "Total Characters: " << cnt << endl;

	return 0;
}
















