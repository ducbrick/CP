// Problem: Flight Routes
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1196
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cassert>
#include <cstdint>
#include <functional>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

const int N = 1e5;

vector<pair<int, int>> adj[N + 1];

int f[N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back({v, w});
	}

	int s = 1;
	int t = n;

	priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> q;

	q.push({0, s});

	while (q.empty() == false) {
		auto [du, u] = q.top();
		q.pop();

		if (f[u] == k)
			continue;

		f[u]++;

		if (u == t) {
			cout << du << ' ';

			if (f[u] == k)
				break;
		}

		for (auto [v, w] : adj[u]) {
			int64_t dv = du + w;
			q.push({dv, v});
		}
	}

	return 0;
}
