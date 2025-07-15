// Problem: Distinct Values Subarrays II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2428
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

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int64_t res = 0;
	map <int, int> f;

	for (int l = 1, r = 1; r <= n; r++) {
		f[a[r]]++;

		while ((int)f.size() > k) {
			f[a[l]]--;

			if (f[a[l]] == 0)
				f.erase(a[l]);

			l++;
		}

		res += r - l + 1;
	}

	cout << res;

	return 0;
}
