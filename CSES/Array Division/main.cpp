// Problem: Array Division
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1085
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <numeric>
using namespace std;

const int MAX_N = 2e5;

int a[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int64_t l = *max_element(a + 1, a + n + 1);
	int64_t r = accumulate(a + 1, a + n + 1, (int64_t)0);
	int64_t res = 0;

	while (l <= r) {
		int64_t m = (l + r) / 2;

		int cnt = 1;
		int64_t s = 0;

		for (int i = 1; i <= n; i++) {
			s += a[i];

			if (s > m) {
				cnt++;
				s = a[i];
			}
		}

		if (cnt <= k) {
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
