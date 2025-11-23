#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solve(int amount, int* deno, int n) {
	if (amount == 0) {
		return 0;
	}

	int ans = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		if (amount >= deno[i]) {
			int chotiAmount = amount - deno[i];
			int chotaAns = solve(chotiAmount, deno, n);
			// Agar chotaAns is INT_MAX, means iske liye ans is not possible
			if (chotaAns != INT_MAX) {
				ans = min(ans, chotaAns + 1);
			}
		}
	}

	return ans;
}


int topDown(int amount, int* deno, int n, vector<int> &dp) {
	if (amount == 0) {
		return 0;
	}

	if (dp[amount] != -1) {
		return dp[amount];
	}

	int ans = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		if (amount >= deno[i]) {
			int chotiAmount = amount - deno[i];
			int chotaAns = topDown(chotiAmount, deno, n, dp);
			// Agar chotaAns is INT_MAX, means iske liye ans is not possible
			if (chotaAns != INT_MAX) {
				ans = min(ans, chotaAns + 1);
			}
		}
	}

	dp[amount] = ans;
	return ans;
}

int bottomUp(int amount, int *deno, int n) {
	int dp[10000];
	dp[0] = 0;

	for (int i = 1; i <= amount; ++i)
	{
		int ans = INT_MAX;
		for (int k = 0; k < n; ++k)
		{
			if (i >= deno[k]) {
				int ci = i - deno[k];
				if (dp[ci] != INT_MAX) {
					ans = min(ans, dp[ci] + 1);
				}
			}
		}

		dp[i] = ans;
	}

	return dp[amount];
}

int main() {

	int deno[] = {2, 7, 10};
	int n = sizeof(deno) / sizeof(int);
	int amount = 35;
	vector<int> dp(amount + 1, -1);
	cout << topDown(amount, deno, n, dp) << endl;
	cout << bottomUp(amount, deno, n) << endl;
	cout << solve(amount, deno, n) << endl;

	return 0;
}
















