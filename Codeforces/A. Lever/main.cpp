// Problem: A. Lever
// Contest: Codeforces Round 1042 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2131/problem/A
// Memory Limit: 256
// Time Limit: 2000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int a[N + 1];
int b[N + 1];

int solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	int res = 1;

	for (int i = 1; i <= n; i++) {
		if (a[i] < b[i])
			continue;

		res += a[i] - b[i];
	}

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
