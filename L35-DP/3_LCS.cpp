#include <iostream>
#include <cstring>
using namespace std;

int solve(string &s1, string &s2, int n, int m, int dp[][1000]) {
	if (n == 0 or m == 0) {
		return 0;
	}

	if (dp[n][m] != -1) {
		return dp[n][m];
	}


	if (s1[n - 1] == s2[m - 1]) {
		return dp[n][m] = 1 + solve(s1, s2, n - 1, m - 1, dp);
	}
	else {
		return dp[n][m] = max(solve(s1, s2, n - 1, m, dp),
		                      solve(s1, s2, n, m - 1, dp));
	}
}

int bottomUp(string &s1, string &s2) {
	int s1_len = s1.size();
	int s2_len = s2.size();
	int dp[1000][1000] = {};

	for (int i = 1; i <= s1_len; ++i)
	{
		for (int j = 1; j <= s2_len; ++j)
		{
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(
				               dp[i][j - 1],
				               dp[i - 1][j]
				           );
			}
		}
	}

	return dp[s1_len][s2_len];
}

void printLCS(string &s1, string &s2, int n, int m, int dp[][1000], string op = "") {
	if (n == 0 or m == 0) {
		reverse(op.begin(), op.end());
		cout << op << endl;
		return;
	}


	if (s1[n - 1] == s2[m - 1]) {
		printLCS(s1, s2, n - 1, m - 1, dp, op + s1[n - 1]);
	}
	else {
		if (dp[n][m] == dp[n - 1][m]) {
			printLCS(s1, s2, n - 1, m , dp, op );
		}
		if (dp[n][m] == dp[n][m - 1]) {
			printLCS(s1, s2, n, m - 1, dp, op );
		}
	}
}

int main() {

	int dp[1000][1000];
	memset(dp, -1 , sizeof(dp));
	string s1 = "abced";
	string s2 = "acbed";

	cout << solve(s1, s2, s1.size(), s2.size(), dp) << endl;
	cout << bottomUp(s1, s2) << endl;
	printLCS(s1, s2, s1.size(), s2.size(), dp);


	return 0;
}














