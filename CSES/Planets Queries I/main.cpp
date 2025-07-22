// Problem: Planets Queries I
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1750
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const int N = 2e5;
const int K = 1e9;
const int L = 30;

int nxt[N + 1][L + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	for (int u = 1; u <= n; u++) {
		cin >> nxt[u][0];
	}

	for (int l = 1; l <= L; l++) {
		for (int u = 1; u <= n; u++) {
			int v = nxt[u][l - 1];
			nxt[u][l] = nxt[v][l - 1];
		}
	}

	while (q--) {
		int u, k;
		cin >> u >> k;

		while (k > 0) {
			int l = log2(k);
			u = nxt[u][l];
			k -= (1 << l);
		}

		cout << u << ' ';
	}

	return 0;
}
