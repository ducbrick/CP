// Problem: A. Redstone?
// Contest: Codeforces Round 1044 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2133/problem/A
// Memory Limit: 256
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <map>
using namespace std;

string solve() {
	int n;
	cin >> n;

	map<int, int> f;

	bool res = false;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		f[a]++;
		res |= (f[a] >= 2);
	}

	return (res ? "YES" : "NO");
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
