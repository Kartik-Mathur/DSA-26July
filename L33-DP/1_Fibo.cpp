#include <iostream>
#include <vector>
using namespace std;

int fibo(int n) { // T.C -> 2^N
	if (n <= 1) {
		return n;
	}

	return fibo(n - 1) + fibo(n - 2);
}


int topDown(int n, vector<int> &dp) { // O(N)
	if (n <= 1) {
		return n;
	}

	if (dp[n] != -1) { // nth fibo calculate ho chuka hai
		return dp[n];
	}
	// Recursion jo bhi ans laaega store krlo
	dp[n] = topDown(n - 1, dp) + topDown(n - 2, dp);
	return dp[n];
}

int bottomUp(int n) {
	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main() {

	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	// int dp[10000];
	// memset(dp, -1, sizeof dp); // cstring header file include krni padegi
	cout << topDown(n, dp) << endl;
	cout << fibo(n) << endl;

	return 0;
}
















