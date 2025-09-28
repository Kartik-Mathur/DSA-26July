#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int a[][9], int i, int j, int n, int number) {
	for (int k = 0; k < n; ++k)
	{
		if (a[k][j] == number || a[i][k] == number) {
			return false;
		}
	}

	// Check box
	n = sqrt(n);
	int si = (i / n) * n;
	int sj = (j / n) * n;

	for (int i = si; i < si + n; ++i)
	{
		for (int j = sj; j < sj + n; ++j)
		{
			if (a[i][j] == number) {
				return false;
			}
		}
	}

	return true;
}


bool sudokuSolver(int a[][9], int i, int j, int n) {
	// base case
	if (i == n) {
		// Print sudoku
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}

	// Agar ek row khatam ho gai toh kya krein
	if (j == n) {
		// Ask recursion to solve the sudoku from i+1,0 coordinates
		return sudokuSolver(a, i + 1, 0, n);
	}

	// Already filled cell ka kya krna hai
	if (a[i][j] != 0) {
		return sudokuSolver(a, i, j + 1, n);
	}

	// recursive case
	// Ek empty cell hum fill krenge baaki recursion ko bolenge
	for (int number = 1; number <= 9; ++number)
	{
		if (isSafe(a, i, j, n, number)) {
			a[i][j] = number;
			// Baaki ka recursion se pucho
			bool kyaBakiBaatBani = sudokuSolver(a, i, j + 1, n);
			if (kyaBakiBaatBani) {
				return true;
			}
			a[i][j] = 0; // Backtracking
		}
	}

	// Agar 1,9 koi bhi number place nhi ho paaya toh means return false...
	return false;
}

int main() {
	int mat[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	sudokuSolver(mat, 0, 0, 9);

	return 0;
}
















