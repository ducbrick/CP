// Problem: Subarray Sums II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1661
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

	int64_t x;
	cin >> x;

	map <int64_t, int> f;
	int64_t res = 0;
	int64_t s = 0;

	f[0]++;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		s += a;

		res += f[s - x];
		f[s]++;
	}

	cout << res;

	return 0;
}
