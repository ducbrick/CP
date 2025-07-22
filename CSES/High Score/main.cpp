// Problem: High Score
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1673
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <tuple>
#include <vector>
using namespace std;

const int N = 2500;
const int M = 5000;
const int64_t INF = 1e18;

tuple<int, int, int> edges[M + 1];
bool can_reach_t[N + 1];
int64_t d[N + 1];

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

	int s = 1;
	int t = n;
	
	fill(can_reach_t + 1, can_reach_t + n + 1, false);

	can_reach_t[t] = true;

	for (int cycle = 1; cycle <= n; cycle++) {
		bool optimizing = false;

		for (int i = 1; i <= m; i++) {
			auto [u, v, w] = edges[i];

			if (can_reach_t[v] == false) {
				continue;
			}

			if (can_reach_t[u]) {
				continue;
			}

			can_reach_t[u] = true;
			optimizing = true;
		}

		if (optimizing == false) {
			break;
		}
	}

	fill(d + 1, d + n + 1, -INF);

	d[s] = 0;

	bool optimizing = false;

	for (int cycle = 1; cycle <= n; cycle++) {
		optimizing = false;
		
		for (int i = 1; i <= m; i++) {
			auto [u, v, w] = edges[i];

			if (d[u] == -INF) {
				continue;
			}

			if (can_reach_t[u] == false) {
				continue;
			}

			if (d[u] + w <= d[v]) {
				continue;
			}

			d[v] = d[u] + w;
			optimizing = true;
		}

		if (optimizing == false) {
			break;
		}
	}

	if (optimizing) {
		cout << -1;
		return 0;
	}

	cout << d[t];

	return 0;
}
