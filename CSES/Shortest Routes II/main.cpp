// Problem: Shortest Routes II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1672
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int N = 500;
const int64_t INF = 1e18;

int64_t d[N + 1][N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			d[u][v] = (u == v ? 0 : INF);
		}
	}

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;

		d[u][v] = min(d[u][v], (int64_t) w);
		d[v][u] = min(d[v][u], (int64_t) w);
	}

	for (int k = 1; k <= n; k++)
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++) 
				d[u][v] = min(d[u][v], d[u][k] + d[k][v]);

	while (q--) {
		int u, v;
		cin >> u >> v;

		cout << (d[u][v] == INF ? -1 : d[u][v]) << '\n';
	}

	return 0;
}
