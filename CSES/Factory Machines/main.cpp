// Problem: Factory Machines
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1620
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int MAX_N = 2e5;

int a[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, t;
	cin >> n >> t;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int64_t l = 0;
	int64_t r = (int64_t) *min_element(a + 1, a + n + 1) * t;
	int64_t res = r;

	while (l <= r) {
		int64_t m = (l + r) / 2;

		int64_t cnt = 0;

		for (int i = 1; i <= n; i++) {
			cnt += m / a[i];
		}

		if (cnt >= t) {
			res = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << res;

	return 0;
}
