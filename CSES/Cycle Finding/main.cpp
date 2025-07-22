// Problem: Cycle Finding
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1197
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

int p[N + 1];
int64_t d[N + 1];

bool visited[N + 1];

void trace(int s) {
	while (true) {
		if (visited[s]) {
			break;
		}

		visited[s] = true;
		s = p[s];
	}

	vector<int> path = {s};

	int u = s;

	do {
		u = p[u];
		path.push_back(u);
	}
	while (u != s);

	reverse(path.begin(), path.end());

	for (int u : path) {
		cout << u << ' ';
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
	}

	for (int cycle = 1; cycle <= n; cycle++) {
		bool optimizing = false;

		for (int i = 1; i <= m; i++) {
			auto [u, v, w] = edges[i];

			if (d[u] + w >= d[v]) {
				continue;
			}

			p[v] = u;
			d[v] = d[u] + w;
			optimizing = true;

			if (cycle == n) {
				cout << "YES\n";
				trace(v);
				return 0;
			}
		}

		if (optimizing == false) {
			break;
		}
	}

	cout << "NO";

	return 0;
}
