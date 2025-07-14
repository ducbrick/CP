// Problem: Sum of Two Values
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1640
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

pair <int, int> a[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a + 1, a + n + 1);

	for (int l = 1, r = n; l <= n; l++) {
		while (l < r && a[l].first + a[r].first > x)
			r--;

		if (l < r && a[l].first + a[r].first == x) {
			cout << a[l].second << ' '  << a[r].second;
			return 0;
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}
