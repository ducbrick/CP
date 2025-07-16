// Problem: Rectangle Cutting
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1744
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int AB = 500;
const int INF = 1e9;

int f[AB + 1][AB + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (i == j)
				continue;

			f[i][j] = INF;

			for (int k = 1; k < i; k++) {
				f[i][j] = min(f[i][j], f[k][j] + f[i - k][j] + 1);
			}

			for (int k = 1; k < j; k++) {
				f[i][j] = min(f[i][j], f[i][k] + f[i][j - k] + 1);
			}
		}
	}

	cout << f[a][b];

	return 0;
}
