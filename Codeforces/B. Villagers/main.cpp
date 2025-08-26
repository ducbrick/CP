// Problem: B. Villagers
// Contest: Codeforces Round 1044 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2133/problem/B
// Memory Limit: 256
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int N = 2e5;

int g[N + 1];

int64_t solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> g[i];
	}

	sort(g + 1, g + n + 1);

	int64_t res = 0;

	for (int i = n; i >= 1; i -= 2) {
		res += g[i];
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
