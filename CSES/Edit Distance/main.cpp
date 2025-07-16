// Problem: Edit Distance
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1639
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
const int M = 5000;
const int INF = 1e9;

int dp[2][M + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, t;
	cin >> s >> t;

	int n = s.size();
	int m = t.size();
	s = '#' + s;
	t = '#' + t;

	for (int j = 0; j <= m; j++) {
		dp[0][j] = j;
	}

	for (int i = 1; i <= n; i++) {
		int* curr = dp[i % 2];
		int* prev = dp[1 - i % 2];

		curr[0] = i;

		for (int j = 1; j <= m; j++) {
			curr[j] = min({
				curr[j - 1] + 1,
				prev[j] + 1,
				prev[j - 1] + (s[i] != t[j])
			});
		}
	}

	cout << dp[n % 2][m];

	return 0;
}
