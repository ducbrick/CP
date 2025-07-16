// Problem: Two Sets II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1093
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int N = 500;
const int S = N * (N + 1) / 4;
const int MOD = 1e9 + 7;

int f[S + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int target = n * (n + 1) / 2;

	if (target % 2 != 0) {
		cout << 0;
		return 0;
	}

	target /= 2;

	f[0] = 1;

	for (int i = 1; i < n; i++) {
		for (int s = target; s >= i; s--) {
			f[s] += f[s - i];
			f[s] %= MOD;
		}
	}

	cout << f[target];

	return 0;
}
