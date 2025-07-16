// Problem: Maximum Subarray Sum II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1644
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

	int n, l, r;
	cin >> n >> l >> r;

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	
	multiset <int64_t> q;
	int64_t res = INT64_MIN;

	for (int i = 1; i <= n; i++) {
		if (i - l >= 0) {
			q.insert(s[i - l]);
		}

		if (i - r - 1 >= 0) {
			q.erase(q.find(s[i - r - 1]));
		}

		if (q.empty())
			continue;

		res = max(res, s[i] - *q.begin());
	}

	cout << res;

	return 0;
}
