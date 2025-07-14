// Problem: Apartments
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1084
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;
const int MAX_M = 2e5;

int a[MAX_N + 1];
int b[MAX_M + 1];

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= m; i++)
		cin >> b[i];

	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);

	int res = 0;

	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= m && b[j] < a[i] - k)
			j++;

		if (j > m)
			break;

		if (b[j] <= a[i] + k) {
			res++;
			j++;
		}
	}

	cout << res;

	return 0;
}
