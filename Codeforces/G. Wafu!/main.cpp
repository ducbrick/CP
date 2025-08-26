// Problem: G. Wafu!
// Contest: Codeforces Round 1042 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2131/problem/G
// Memory Limit: 256
// Time Limit: 3000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int N = 2e5;
const int S = 31;
const int MOD = 1e9 + 7;

int ss[N + 1];
int64_t f[S + 1];

void prepare() {
	int64_t product = 1;

	for (int s = 1; s <= S; s++) {
		f[s] = s * product % MOD;
		product = product * f[s] % MOD;
	}
}

int64_t recur(int s, int k) {
	if (k == 0) {
		return 1;
	}

	if (k == 1) {
		return s % MOD;
	}

	int64_t res = s % MOD;
	k--;

	for (int smaller_s = 1; smaller_s < s; smaller_s++) {
		int64_t cnt = (1LL << (smaller_s - 1));

		if (smaller_s > S || cnt > k) {
			return res * recur(smaller_s, k) % MOD;
		}

		res = res * f[smaller_s] % MOD;
		k -= cnt;
	}

	return res;
}

int solve() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int& s = ss[i];
		cin >> s;
	}

	sort(ss + 1, ss + n + 1);

	int64_t res = 1;

	for (int i = 1; i <= n; i++) {
		int s = ss[i];
		int64_t cnt = (1LL << (s - 1));

		if (s > S || cnt > k) {
			return res * recur(s, k) % MOD;
		}

		res = res * f[s] % MOD;
		k -= cnt;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	prepare();

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
