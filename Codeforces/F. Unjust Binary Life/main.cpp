// Problem: F. Unjust Binary Life
// Contest: Codeforces Round 1042 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2131/problem/F
// Memory Limit: 256
// Time Limit: 2000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <memory>
using namespace std;

const int N = 2e5;

int a[N + 1];
int b[N + 1];

int64_t solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		a[i] = a[i - 1] + (c == '0' ? 1 : -1);
	}

	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		b[i] = b[i - 1] + (c == '0' ? -1 : 1);
	}

	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);

	for (int i = 1; i <= n; i++) {
		cerr << a[i] << " \n"[i == n];
	}

	for (int i = 1; i <= n; i++) {
		cerr << b[i] << " \n"[i == n];
	}

	int64_t res = 0;

	for (int i = 1; i <= n; i++) {
		int j = lower_bound(b + 1, b + n + 1, a[i]) - b - 1;
		res += (int64_t) j * a[i];
		res -= (int64_t) (n - j) * a[i];
	}

	for (int j = 1; j <= n; j++) {
		int i = upper_bound(a + 1, a + n + 1, b[j]) - a - 1;
		res += (int64_t) i * b[j];
		res -= (int64_t) (n - i) * b[j];
	}

	res = (int64_t) n * n * (n + 1) / 2 - res / 2;

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
