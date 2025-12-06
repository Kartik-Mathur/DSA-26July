#include <iostream>
using namespace std;

int solve(int n, int k) { // O(k^n)
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}

	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += solve(n - i, k);
	}

	return ans;
}

int topDown(int n, int k, int *dp) { // O(n*k)
	if (n == 0) {
		return 1;
	}

	if (n < 0) {
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		ans += topDown(n - i, k, dp);
	}

	return dp[n] = ans;
}

int bottomUp(int n, int k) { // O(n*k)
	int *dp = new int[n + 1] {0};

	dp[0] = 1; // Initialisation
	for (int i = 1; i <= n; ++i)
	{

		for (int j = 1; j <= k and i - j >= 0; ++j)
		{
			dp[i] += dp[i - j];
		}
	}

	return dp[n];
}

int bottomUp2(int n, int k) {
	int *dp = new int[n + 1] {0};

	dp[0] = 1; // Initialisation
	dp[1] = 1; // Initialisation
	for (int i = 2; i <= n; ++i)
	{

		dp[i] = 2 * dp[i - 1] - (i - 1 - k >= 0 ? dp[i - 1 - k] : 0);
	}

	return dp[n];
}
int main() {
	int n = 4, k = 3;
	int dp[10000];

	memset(dp, -1, sizeof dp);
	cout << topDown(n, k, dp) << endl;
	cout << bottomUp(n, k) << endl;
	cout << bottomUp2(n, k) << endl;
	cout << solve(n, k) << endl;

	return 0;
}
















