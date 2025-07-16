// Problem: Dice Combinations
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1633
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
const int MOD = 1e9 + 7;

int f[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	f[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int d = 1; d <= 6; d++) {
			if (i - d < 0)
				continue;

			f[i] += f[i - d];
			f[i] %= MOD;
		}
	}

	cout << f[n];

	return 0;
}
