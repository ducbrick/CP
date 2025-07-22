// Problem: Road Construction
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1676
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
#include <set>
#include <tuple>
using namespace std;

const int N = 1e5;

int dsu[N + 1];

int get_leader(int u) {
	if (dsu[u] < 0)
		return u;
	return (dsu[u] = get_leader(dsu[u]));
}

int get_size(int u) {
	u = get_leader(u);
	return -dsu[u];
}

void connect(int u, int v) {
	u = get_leader(u);
	v = get_leader(v);

	if (u == v)
		return;

	if (get_size(u) < get_size(v))
		swap(u, v);

	dsu[u] += dsu[v];
	dsu[v] = u;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	multiset<int> q;

	for (int u = 1; u <= n; u++) {
		dsu[u] = -1;
		q.insert(1);
	}

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;

		if (get_leader(u) != get_leader(v)) {
			q.erase(q.find(get_size(u)));
			q.erase(q.find(get_size(v)));

			connect(u, v);

			q.insert(get_size(u));
		}

		cout << q.size() << ' ' << *q.rbegin() << '\n';
	}

	return 0;
}
