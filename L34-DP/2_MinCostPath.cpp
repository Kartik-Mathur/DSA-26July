#include <iostream>
using namespace std;

int main() {

	int cost[][10] = {
		{1, 1, 3, 4},
		{6, 1, 1, 5},
		{7, 3, 1, 1},
		{2, 5, 4, 1}
	};

	int dp[100][100] = {0};
	int n = 4, m = 4;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i == 0 and j == 0) {
				dp[i][j] = cost[i][j];
			}
			else {
				dp[i][j] = min(
				               (i - 1 >= 0 ? dp[i - 1][j] : INT_MAX),
				               (j - 1 >= 0 ? dp[i][j - 1] : INT_MAX)
				           ) + cost[i][j];
			}
		}
	}

	cout << dp[n - 1][m - 1] << endl;

	return 0;
}
















