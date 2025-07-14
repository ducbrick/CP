// Problem: Collecting Numbers
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2216
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

bool seen[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int res = 0;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		if (seen[a - 1] == false)
			res++;

		seen[a] = true;
	}

	cout << res;

	return 0;
}
