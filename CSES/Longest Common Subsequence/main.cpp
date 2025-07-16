// Problem: Longest Common Subsequence
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3403
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
const int M = 5000;

int a[N + 1];
int b[M + 1];
int dp[N + 1][M + 1];

void trace(int i, int j) {
	if (i == 0 || j == 0)
		return;

	if (dp[i][j] == dp[i - 1][j])
		return trace(i - 1, j);

	if (dp[i][j] == dp[i][j - 1])
		return trace(i, j - 1);

	trace(i - 1, j - 1);
	cout << a[i] << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int j = 1; j <= n; j++) {
		cin >> b[j];
	}

	for (int i = 1; i <= n; i++) {
		int* curr = dp[i];
		int* prev = dp[i - 1];

		for (int j = 1; j <= m; j++) {
			curr[j] = max({
				curr[j - 1],
				prev[j],
				prev[j - 1] + (a[i] == b[j])
			});
		}
	}

	cout << dp[n][m] << '\n';
	trace(n, m);

	return 0;
}
