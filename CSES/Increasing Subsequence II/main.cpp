// Problem: Increasing Subsequence II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1748
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <locale>
#include <vector>
using namespace std;

const int N = 2e5;
const int MOD = 1e9 + 7;

int a[N + 1];
int bit[N + 1];

void update(int i, int lim, int delta) {
	delta %= MOD;

	for ( ; i <= lim; i += i & (-i)) {
		bit[i] += delta;
		bit[i] %= MOD;
	}
}

int get(int i) {
	int res = 0;

	for ( ; i > 0; i -= i & (-i)) {
		res += bit[i];
		res %= MOD;
	}

	return res;
}


void compress(int n) {
	vector<int> values;

	for (int i = 1; i <= n; i++) {
		values.push_back(a[i]);
	}

	sort(values.begin(), values.end());

	for (int i = 1; i <= n; i++) {
		a[i] = upper_bound(values.begin(), values.end(), a[i]) - values.begin();
	}
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

	compress(n);

	int res = 0;

	for (int i = 1; i <= n; i++) {
		int cnt = get(a[i] - 1) + 1;

		res += cnt;
		res %= MOD;

		update(a[i], n, cnt);
	}

	cout << res;

	return 0;
}
