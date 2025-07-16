// Problem: Removal Game
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1097
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int N = 5000;
const int64_t INF = 1e18;

int a[N + 1];
int64_t f[N + 1][N + 1];

int64_t play(int l, int r, bool first) {
	if (r < l)
		return 0;

	if (f[l][r] != INF)
		return f[l][r];

	int64_t choice_l = play(l + 1, r, !first);
	int64_t choice_r = play(l, r - 1, !first);

	if (first)
		f[l][r] = max(choice_l + a[l], choice_r + a[r]);
	else
		f[l][r] = min(choice_l, choice_r);

	return f[l][r];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int l = 1; l <= n; l++) {
		for (int r = 1; r <= n; r++) {
			f[l][r] = INF;
		}
	}

	cout << play(1, n, true);

	return 0;
}
