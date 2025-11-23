#include <iostream>
#include <vector>

using namespace std;

int solve(int n) {
	if (n == 1) {
		return 0;
	}

	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

	if (n % 3 == 0) {
		op1 = solve(n / 3);
	}
	if (n % 2 == 0) {
		op2 = solve(n / 2);
	}
	op3 = solve(n - 1);

	return min(op1, min(op2, op3)) + 1;
}

int topDown(int n, vector<int> &dp) {
	if (n == 1) {
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

	if (n % 3 == 0) op1 = topDown(n / 3, dp);
	if (n % 2 == 0) op2 = topDown(n / 2, dp);
	op3 = topDown(n - 1, dp);

	dp[n] = min(op1, min(op2, op3)) + 1;
	return dp[n];
}

int bottomUp(int n) {
	vector<int> dp(n + 1);
	dp[1] = 0; // Initialisation

	for (int i = 2; i <= n; ++i)
	{
		int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
		if (i % 3 == 0) op1 = dp[i / 3];
		if (i % 2 == 0) op2 = dp[i / 2];
		op3 = dp[i - 1];
		dp[i] = min(op1, min(op2, op3)) + 1;
	}

	return dp[n];
}

int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	cout << topDown(n, dp) << endl;
	cout << bottomUp(n) << endl;
	cout << solve(n) << endl;

	return 0;
}
















