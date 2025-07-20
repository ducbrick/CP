// Problem: Round Trip
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1669
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 1e5;

vector<int> adj[N + 1];
int p[N + 1];

void trace(int s) {
	int u = s;

	vector<int> path;

	do {
		path.push_back(u);
		u = p[u];
	} while (u != s);
	path.push_back(s);

	cout << path.size() << '\n';

	for (int u : path) {
		cout << u << ' ';
	}
}

void dfs(int u, int parent) {

	if (p[u] != 0) {
		p[u] = parent;
		trace(u);
		exit(0);
	}

	p[u] = parent;

	for (int v : adj[u]) {
		if (v == parent) {
			continue;
		}

		dfs(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int u = 1; u <= n; u++) {
		if (p[u] != 0) {
			continue;
		}

		dfs(u, -1);
	}

	cout << "IMPOSSIBLE";

	return 0;
}
