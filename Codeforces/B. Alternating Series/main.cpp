// Problem: B. Alternating Series
// Contest: Codeforces Round 1042 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2131/problem/B
// Memory Limit: 256
// Time Limit: 2000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int a[N + 1];

void solve(int n) {

	if (n == 2) {
		a[1] = -1;
		a[2] = 2;
		return;
	}

	for (int i = 1; i <= n; i += 2) {
		a[i] = -1;
	}

	for (int i = 2; i <= n; i += 2) {
		a[i] = 3;
	}

	if (n % 2 == 0) {
		a[n] = 2;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		solve(n);

		for (int i = 1; i <= n; i++) {
			cout << a[i] << ' ';
		}

		cout << '\n';
	}

	return 0;
}
