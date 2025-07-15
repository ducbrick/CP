// Problem: Distinct Values Subarrays
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3420
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int MAX_N = 2e5;

int a[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	set <int> f;

	int64_t res = 0;

	for (int l = 1, r = 1; r <= n; r++) {
		while (f.count(a[r])) {
			f.erase(a[l]);
			l++;
		}

		f.insert(a[r]);
		res += r - l + 1;
	}

	cout << res;

	return 0;
}
