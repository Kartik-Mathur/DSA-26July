#include <iostream>
using namespace std;

int main() {

	char ch;
	int cnt = 0;

	// cin >> ch;
	ch = cin.get(); // Yeh whitespace characters ko read krega unhe ignore nahi krega
	while (ch != '$') { // Condition check
		cnt++;

		ch = cin.get();  // Updation of ch bucket
	}

	cout << "Total Characters: " << cnt << endl;

	return 0;
}
















