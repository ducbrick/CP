// Problem: Maximum Subarray Sum
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1643
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int64_t res = INT64_MIN;
	int64_t sum = 0;

	for (int i = 1; i <= n; i++) {
		int64_t a;
		cin >> a;

		sum += a;
		res = max(res, sum);
		sum = max(sum, (int64_t) 0);
	}

	cout << res;
	
	return 0;
}
