// Problem: Investigation
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1202
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5;
const int64_t INF = 1e18;
const int MOD = 1e9 + 7;

vector<pair<int, int>> adj[N + 1];

int64_t d[N + 1];
int64_t paths[N + 1];
int64_t min_nodes[N + 1];
int64_t max_nodes[N + 1];

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
	int t = n;

	fill(d + 1, d + n + 1, INF);

	priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> q;

	d[s] = 0;
	paths[s] = 1;
	min_nodes[s] = 0;
	max_nodes[s] = 0;

	q.push({0, s});

	while (q.empty() == false) {
		auto [du, u] = q.top();
		q.pop();

		if (du != d[u])
			continue;

		for (auto [v, w] : adj[u]) {
			int64_t dv = du + w;

			if (dv > d[v])
				continue;

			if (dv == d[v]) {
				paths[v] = (paths[v] + paths[u]) % MOD;
				min_nodes[v] = min(min_nodes[v], min_nodes[u] + 1);
				max_nodes[v] = max(max_nodes[v], max_nodes[u] + 1);
				continue;
			}

			d[v] = dv;
			paths[v] = paths[u];
			min_nodes[v] = min_nodes[u] + 1;
			max_nodes[v] = max_nodes[u] + 1;

			q.push({dv, v});
		}
	}

	cout << d[t] << ' ';
	cout << paths[t] << ' ';
	cout << min_nodes[t] << ' ';
	cout << max_nodes[t] << ' ';

	return 0;
}
