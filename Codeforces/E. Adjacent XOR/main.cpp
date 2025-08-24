// Problem: E. Adjacent XOR
// Contest: Codeforces Round 1042 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2131/problem/E
// Memory Limit: 256
// Time Limit: 2000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int a[N + 1];
int b[N + 1];

string solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	if (a[n] != b[n]) {
		return "NO";
	}

	for (int i = 1; i <= n - 1; i++) {
		if (a[i] == b[i]) {
			continue;
		}

		if ((a[i] ^ a[i + 1]) == b[i]) {
			continue;
		}

		if (b[i + 1] != (a[i] ^ b[i])) {
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
