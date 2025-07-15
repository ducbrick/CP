// Problem: Subarray Sums I
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1660
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int MAX_N = 2e5;

int64_t s[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int64_t x;
	cin >> x;

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] += s[i - 1];
	}

	int64_t res = 0;

	for (int l = 1, r = 1, i = 1; i <= n; i++) {
		while (l <= i && s[i] - s[l - 1] > x)
			l++;

		r = max(r, l);

		while (r <= i && s[i] - s[r - 1] >= x)
			r++;

		if (l <= i)
			res += r - l;
	}

	cout << res;

	return 0;
}
