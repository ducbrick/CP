// Problem: Shortest Routes I
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1671
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
#include <cstring>
#include <functional>
#include <vector>
using namespace std;

const int N = 1e5;
const int64_t INF = 1e18;

vector<pair<int, int>> adj[N + 1];
int64_t d[N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v, w});
	}

	int s = 1;

	for (int u = 1; u <= n; u++) {
		d[u] = INF;
	}

	priority_queue<pair<int64_t, int>, vector<pair <int64_t, int>>, greater<>> q;

	d[s] = 0;
	q.push({0, s});

	while (q.empty() == false) {
		auto [du, u] = q.top();
		q.pop();

		if (du != d[u]) {
			continue;
		}

		for (auto [v, w] : adj[u]) {
			if (du + w >= d[v]) {
				continue;
			}

			d[v] = du + w;
			q.push({d[v], v});
		}
	}

	for (int u = 1; u <= n; u++) {
		cout << d[u] << ' ';
	}

	return 0;
}
