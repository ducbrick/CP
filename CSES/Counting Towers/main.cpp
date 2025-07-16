// Problem: Counting Towers
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2413
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int N = 1e6;
const int MOD = 1e9 + 7;

int64_t connected[N + 1];
int64_t detached[N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	connected[1] = detached[1] = 1;

	for (int i = 2; i <= N; i++) {
		connected[i] = (2 * connected[i - 1] + detached[i - 1]) % MOD;
		detached[i] = (connected[i - 1] + 4 * detached[i - 1]) % MOD;
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int res = (connected[n] + detached[n]) % MOD;

		cout << res << ' ';
	}

	return 0;
}
