// Problem: Coin Combinations II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1636
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
const int MAX_X = 1e6;
const int MOD = 1e9 + 7;

int coin[MAX_N + 1];
int cnt[MAX_X + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	cnt[0] = 1;

	for (int i = 1; i <= n; i++)
		for (int v = 1; v <= x; v++) {
			if (v - coin[i] < 0)
				continue;

			cnt[v] += cnt[v - coin[i]];
			cnt[v] %= MOD;
		}

	cout << cnt[x];

	return 0;
}
