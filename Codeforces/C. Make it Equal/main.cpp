// Problem: C. Make it Equal
// Contest: Codeforces Round 1042 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2131/problem/C
// Memory Limit: 256
// Time Limit: 2000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <map>
using namespace std;

const int N = 2e5;

int a[N + 1];
int b[N + 1];

string solve() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = a[i] % k;
		a[i] = min(a[i], (k - a[i]) % k);
	}

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		b[i] = b[i] % k;
		b[i] = min(b[i], (k - b[i]) % k);
	}

	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);

	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			return "NO";
		}
	}

	return "YES";
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
