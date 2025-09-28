#include <iostream>
using namespace std;

bool isSafe(int board[][100], int i, int j, int n) {
	// Check current column for queen
	for (int r = 0; r < i; ++r)
	{
		if (board[r][j] == 1) {
			return false;
		}
	}

	int oi = i;
	int oj = j;
	// Check upper left diagonal for queen
	while (i >= 0 and j >= 0) {
		if (board[i][j] == 1) {
			return false;
		}
		i--;
		j--;
	}

	i = oi;
	j = oj;
	// Check upper right diagonal for queen
	while (i >= 0 and j < n) {
		if (board[i][j] == 1) {
			return false;
		}
		i--;
		j++;
	}

	return true;
}

bool nQueen(int board[][100], int row, int n) {
	// base case
	if (row == n) {
		// Print the solution...
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == 1) {
					cout << "Q ";
				}
				else {
					cout << "_ ";
				}
			}
			cout << endl;
		}

		return false;
	}

	// recursive case
	for (int col = 0; col < n; ++col)
	{
		if (isSafe(board, row, col, n)) {
			board[row][col] = 1; // Place the queen

			bool kyaBakiPlaceHui = nQueen(board, row + 1, n);
			if (kyaBakiPlaceHui) {
				return true;
			}

			board[row][col] = 0; // backtracking
		}
	}

	return false; // Agar kisi bhi col mei queen place nhi hui toh possible nhi hai answer...
}

int main() {

	int board[100][100] = {0};
	int n;
	cin >> n;
	nQueen(board, 0, n);

	return 0;
}
















