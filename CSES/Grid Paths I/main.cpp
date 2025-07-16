// Problem: Grid Paths I
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1638
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int MOD = 1e9 + 7;

int cnt[2][N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cnt[0][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;

			cnt[i % 2][j] = 0;

			if (c == '*')
				continue;

			cnt[i % 2][j] = cnt[i % 2][j - 1] + cnt[1 - i % 2][j];
			cnt[i % 2][j] %= MOD;
		}
	}

	cout << cnt[n % 2][n];

	return 0;
}
