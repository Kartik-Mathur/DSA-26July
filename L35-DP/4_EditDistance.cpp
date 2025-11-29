#include <iostream>
using namespace std;

int topDown(string &s1, string &s2, int n, int m, int dp[][100]) {
	// base case
	if (n == 0) return m;
	if (m == 0) return n;

	if (dp[n][m] != -1) {
		return dp[n][m];
	}

	// recursive case
	if (s1[n - 1] == s2[m - 1]) {
		return dp[n][m] = topDown(s1, s2, n - 1, m - 1, dp);
	}
	else {
		int op1 = topDown(s1, s2, n - 1, m, dp); // Insert
		int op2 = topDown(s1, s2, n - 1, m - 1, dp); // update
		int op3 = topDown(s1, s2, n, m - 1, dp); // delete

		return dp[n][m] = 1 + min(op1, min(op2, op3));
	}
}

int bottomUp(string &s1, string &s2) {
	int n = s1.size();
	int m = s2.size();
	int dp[100][100] = {0};

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if (i == 0 and j == 0) {
				dp[i][j] = 0;
			}
			else if (i == 0) {
				dp[i][j] = j;
			}
			else if (j == 0) {
				dp[i][j] = i;
			}
			else if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(
				               dp[i][j - 1],
				               min(dp[i - 1][j], dp[i - 1][j - 1])
				           ) + 1;
			}
		}
	}


	for (int i = 0; i <= s1.size(); ++i)
	{
		for (int j = 0; j <= s2.size(); ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return dp[n][m];
}

int main() {

	string s1 = "satur";
	string s2 = "sun";

	int dp[100][100];
	memset(dp, -1 , sizeof(dp));

	cout << bottomUp(s1, s2) << endl;

	cout << topDown(s1, s2, s1.size(), s2.size(), dp) << endl;


	return 0;
}
















