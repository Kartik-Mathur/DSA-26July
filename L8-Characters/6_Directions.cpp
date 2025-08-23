#include <iostream>
using namespace std;

int main() {

	char ch;
	int x = 0, y = 0;

	ch = cin.get();
	while (ch != '\n') {

		if (ch == 'S') y--;
		else if (ch == 'N') y++;
		else if (ch == 'E') x++;
		else x--;

		ch = cin.get();
	}

	// E -> N -> S -> W
	if (x >= 0) { // Print karna padega x times 'E'
		for (int i = 0; i < x; ++i)
		{
			cout << 'E';
		}
	}

	char temp;

	if (y >= 0) temp = 'N';
	else temp = 'S';

	y = abs(y); // y = |y|
	for (int i = 0; i < y; ++i)
	{
		cout << temp;
	}

	// W print logic
	if (x <= 0) {
		x = abs(x);
		for (int i = 0; i < x; ++i)
		{
			cout << 'W';
		}
	}

	cout << endl;


	return 0;
}
















