#include <iostream>
using namespace std;

int main() {

	char ch = 'e';
	// cin >> ch;

	switch (ch) {
	case 'N':
	case 'n':
		cout << "North\n";
		break;
	case 'S':
	case 's':
		cout << "South\n";
		break;
	case 'W':
	case 'w':
		cout << "West\n";
		break;
	case 'E':
	case 'e':
		cout << "East\n";
		break;
	default:
		cout << "Invalid character\n";
	}


	return 0;
}
















