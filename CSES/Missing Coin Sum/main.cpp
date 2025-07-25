// Problem: Missing Coin Sum
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2183
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int MAX_N = 2e5;

int a[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	int64_t res = 1;

	for (int i = 1; i <= n; i++) {
		if (a[i] > res)
			break;
		
		res += a[i];
	}

	cout << res;
	return 0;
}
