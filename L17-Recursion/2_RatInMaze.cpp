#include <iostream>
using namespace std;

bool ratInMaze(char maze[][5], int i, int j, int n, int m, int sol[][10]) {
	// base case
	if (i == n - 1 and j == m - 1) {
		// Print the solution
		sol[i][j] = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return false; // Fool the recursion
	}
	// recursive case
	sol[i][j] = 1; // Assume current cell to be the part of solution

	// Check right
	if (j + 1 < m and maze[i][j + 1] != 'X') {
		bool kyaRightSeBaatBani = ratInMaze(maze, i, j + 1, n, m, sol);
		if (kyaRightSeBaatBani) {
			return true;
		}
	}
	// Check down
	if (i + 1 < n and maze[i + 1][j] != 'X') {
		bool kyaNeecheSeBaatBani = ratInMaze(maze, i + 1, j, n, m, sol);
		if (kyaNeecheSeBaatBani) {
			return true;
		}
	}

	// Na right se, Na down se kahi se raasta nahi milla toh i,j sol ka part nhi ho skta
	sol[i][j] = 0; // backtracking
	return false;
}

int main() {

	char maze[][5] = {
		"0000",
		"00XX",
		"0000",
		"XX00",
	};
	int sol[10][10] = {0};
	ratInMaze(maze, 0, 0, 4, 4, sol);

	return 0;
}
















