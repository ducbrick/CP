// Problem: Sum of Three Values
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1641
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5000;

pair <int64_t, int> a[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; i++) {
		auto &[value, index] = a[i];
		cin >> value;
		index = i;
	}

	sort(a + 1, a + n + 1);

	for (int i = 3; i <= n; i++)
		for (int l = 1, r = i - 1; l < r; r--) {
			while (l < r && a[l].first + a[r].first + a[i].first < x)
				l++;

			if (l < r && a[l].first + a[r].first + a[i].first == x) {
				cout << a[l].second << ' ' << a[r].second << ' ' << a[i].second;
				return 0;
			}
		}

	cout << "IMPOSSIBLE";

	return 0;
}
