// Problem: Ferris Wheel
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1090
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

int a[MAX_N + 1];
bool taken[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	int res = 0;

	for (int l = 1, r = n; l <= n; l++) {
		if (taken[l])
			continue;

		res++;

		while (l < r && a[l] + a[r] > x)
			r--;

		if (l < r) {
			taken[r] = true;
			r--;
		}
	}

	cout << res;

	return 0;
}
