// Problem: Money Sums
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1745
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

const int N = 100;
const int A = 1000;
const int S = N * A;

int a[N + 1];
bool f[S + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int max_s = accumulate(a + 1, a + n + 1, 0);

	f[0] = true;

	for (int i = 1; i <= n; i++) {
		for (int s = max_s; s >= a[i]; s--) {
			f[s] |= f[s - a[i]];
		}
	}

	int cnt = accumulate(f + 1, f + max_s + 1, 0);

	cout << cnt << '\n';

	for (int s = 1; s <= max_s; s++)
		if (f[s])
			cout << s << ' ';

	return 0;
}
