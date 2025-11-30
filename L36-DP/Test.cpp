#include <iostream>
using namespace std;

int solve(int *price, int *weight, int n, int capacity) { // O(2^N)
	// base case
	if (capacity == 0 or n == 0) {
		return 0;
	}

	// recursive case
	int op1 = 0, op2 = 0;
	if (weight[n - 1] <= capacity) {
		op1 = price[n - 1] + solve(price, weight, n - 1, capacity - weight[n - 1]);
	}

	op2 = 0 + solve(price, weight, n - 1, capacity);
	return max(op1, op2);
}

// O(N * capacity)
int topDown(int *price, int *weight, int n, int capacity, int dp[][100]) {
	// base case
	if (capacity == 0 or n == 0) {
		return 0;
	}

	if (dp[n][capacity] != -1) {
		return dp[n][capacity];
	}

	// recursive case
	int op1 = 0, op2 = 0;
	if (weight[n - 1] <= capacity) {
		op1 = price[n - 1] + topDown(price, weight, n - 1, capacity - weight[n - 1], dp);
	}

	op2 = 0 + topDown(price, weight, n - 1, capacity, dp);
	return dp[n][capacity] = max(op1, op2);
}

int bottomUp(int *price, int *weight, int n, int capacity) {
	int dp[100][100] = {0};

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= capacity; ++j)
		{
			if (i == 0 or j == 0) {
				dp[i][j] = 0; // i -> 0 means no items, j->0 means no capacity, thus 0 profit
			}
			else {

				int op1 = 0, op2 = 0;
				if (j >= weight[i - 1]) {
					op1 = price[i - 1] + dp[i - 1][j - weight[i - 1]];
				}
				op2 = 0 + dp[i - 1][j];

				dp[i][j] = max(op1, op2);
			}
		}
	}

	return dp[n][capacity];
}


int optimisedKnapsack(int *price, int *weight, int n, int capacity) {
	int dp[2][100] = {0};

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= capacity; ++j)
		{
			if (i == 0 or j == 0) {
				dp[1][j] = 0;
			}
			else {
				int op1 = 0, op2 = 0;
				if (weight[i - 1] <= j) {
					op1 = price[i - 1] + dp[0][j - weight[i - 1]];
				}
				op2 = dp[0][j];

				dp[1][j] = max(op1, op2);
			}
		}

		for (int j = 0; j <= capacity; ++j)
		{
			dp[0][j] = dp[1][j];
		}

	}

	return dp[1][capacity];
}

int main() {
	int price[] = {2, 3, 4, 6};
	int weight[] = {1, 3, 2, 4};
	int n = sizeof(weight) / sizeof(int);
	int dp[100][100];
	memset(dp, -1, sizeof dp);
	cout << topDown(price, weight, n, 5, dp) << endl;
	cout << bottomUp(price, weight, n, 5) << endl;
	cout << optimisedKnapsack(price, weight, n, 5) << endl;
	cout << solve(price, weight, n, 5) << endl;


	return 0;
}
















