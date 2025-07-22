// Problem: Flight Discount
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1195
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
#include <tuple>
#include <vector>
using namespace std;

const int N = 1e5;
const int M = 2e5;
const int64_t INF = 1e18;

tuple<int, int, int> edges[M + 1];

vector<pair<int, int>> norm_adj[N + 1];
vector<pair<int, int>> rev_adj[N + 1];

int64_t d_s[N + 1];
int64_t d_t[N + 1];

void ijk(vector<pair<int, int>> (&adj)[N + 1], int64_t (&d)[N + 1], int s, int n) {
	priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> q;

	fill(d + 1, d + n + 1, INF);

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

			d[v] = d[u] + w;
			q.push({d[v], v});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		auto &[u, v, w] = edges[i];
		cin >> u >> v >> w;

		norm_adj[u].push_back({v, w});
		rev_adj[v].push_back({u, w});
	}

	int s = 1;
	int t = n;

	ijk(norm_adj, d_s, s, n);
	ijk(rev_adj, d_t, t, n);

	int64_t res = INF;

	for (int i = 1; i <= m; i++) {
		auto [u, v, w] = edges[i];
		res = min(res, d_s[u] + w / 2 + d_t[v]);
	}

	cout << res;

	return 0;
}
