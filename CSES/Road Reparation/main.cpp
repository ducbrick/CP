// Problem: Road Reparation
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1675
// Memory Limit: 128
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
#include <tuple>
using namespace std;

const int N = 1e5;
const int M = 2e5;

int dsu[N + 1];

int get_leader(int u) {
	if (dsu[u] < 0)
		return u;
	return (dsu[u] = get_leader(dsu[u]));
}

void connect(int u, int v) {
	u = get_leader(u);
	v = get_leader(v);

	if (u == v)
		return;

	if (-dsu[u] < -dsu[v])
		swap(u, v);

	dsu[u] += dsu[v];
	dsu[v] = u;
}

tuple<int, int, int> edges[M + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		auto &[u, v, w] = edges[i];
		cin >> u >> v >> w;
	}

	sort(edges + 1, edges + m + 1, [](auto a, auto b) {
		auto [ua, va, wa] = a;
		auto [ub, vb, wb] = b;

		return (wa < wb);
	});

	int64_t res = 0;

	fill(dsu + 1, dsu + n + 1, -1);

	for (int i = 1; i <= m; i++) {
		auto [u, v, w] = edges[i];

		if (get_leader(u) == get_leader(v))
			continue;

		res += w;
		connect(u, v);
	}

	for (int u = 1; u <= n; u++)
		if (get_leader(u) != get_leader(1)) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	
	cout << res;

	return 0;
}
