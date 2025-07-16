// Problem: Array Description
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1746
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int N = 1e5;
const int M = 100;
const int MOD = 1e9 + 7;

int64_t dp[2][M + 2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int64_t* curr = dp[i % 2];
		int64_t* prev = dp[1 - i % 2];
		
		fill(curr + 1, curr + m + 1, 0);

		int a;
		cin >> a;

		if (a != 0) {
			curr[a] = (i == 1 ? 1 : prev[a - 1] + prev[a] + prev[a + 1]);
			curr[a] %= MOD;
			continue;
		}

		if (i == 1) {
			fill(curr + 1, curr + m + 1, 1);
			continue;
		}

		for (int v = 1; v <= m; v++) {
			curr[v] = prev[v - 1] + prev[v] + prev[v + 1];
			curr[v] %= MOD;
			continue;
		}
	}

	int res = 0;

	for (int v = 1; v <= m; v++) {
		res += dp[n % 2][v];
		res %= MOD;
	}

	cout << res;

	return 0;
}
