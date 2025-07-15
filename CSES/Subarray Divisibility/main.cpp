// Problem: Subarray Divisibility
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1662
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	map <int, int> f;
	int64_t res = 0;
	int s = 0;

	f[0]++;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		s += a;
		s = (s % n + n) % n;

		res += f[s];
		f[s]++;
	}

	cout << res;

	return 0;
}
