// Problem: Distinct Values Subsequences
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3421
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	map <int, int> count;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		count[a]++;
	}

	int64_t res = 1;

	for (auto [a, f]: count) {
		res = res * (f + 1) % MOD;
	}

	cout << (res - 1 + MOD) % MOD;

	return 0;
}
