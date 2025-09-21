#include <iostream>
using namespace std;

void spiralPrint(int a[][100], int n, int m) {
	int sr = 0, sc = 0, er = n - 1, ec = m - 1;
	while (sr <= er and sc <= ec) {
		// 1. Print sr, [sc, ec]
		for (int c = sc; c <= ec; ++c)
		{
			cout << a[sr][c] << " ";
		}
		sr++;

		// 2. Print ec, [sr, er]
		for (int r = sr; r <= er; ++r)
		{
			cout << a[r][ec] << " ";
		}
		ec--;

		if (sr < er) {
			// 3. Print er, [ec,sc]
			for (int c = ec; c >= sc; --c)
			{
				cout << a[er][c] << " ";
			}
			er--;
		}

		if (sc < ec) {
			// 4. Print sc, [er,sr]
			for (int r = er; r >= sr; --r)
			{
				cout << a[r][sc] << " ";
			}
			sc++;
		}
	}
}

int main() {

	int a[100][100];
	int number = 1;
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			a[i][j] = number;
			number++;
		}
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	spiralPrint(a, r, c);

	return 0;
}
















