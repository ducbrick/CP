// Problem: Reading Books
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1631
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int64_t sum = 0;
	int mx = INT_MIN;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		sum += a;
		mx = max(mx, a);
	}

		cout << max(sum, (int64_t) 2 * mx);
	
	return 0;
}
