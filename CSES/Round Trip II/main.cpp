// Problem: Round Trip II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1678
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 1e5;

vector<int> adj[N + 1];

bool visited[N + 1];
int topo[N + 1];

void dfs(int u) {
	if (visited[u])
		return;

	visited[u] = true;

	for (int v : adj[u]) {
		dfs(v);
	}

	static int i = 1;

	topo[i] = u;
	i++;
}

vector<int> path;

bool trace(int u, int t) {
	if (visited[u])
		return false;

	visited[u] = true;

	if (u == t) {
		path.push_back(u);
		return true;
	}

	for (int v : adj[u]) {
		if (trace(v, t) == false)
			continue;

		path.push_back(u);
		return true;
	}

	return false;
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
	}

	for (int u = 1; u <= n; u++) {
		dfs(u);
	}

	reverse(topo + 1, topo + n + 1);

	fill(visited + 1, visited + n + 1, false);

	for (int i = 1; i <= n; i++) {
		int u = topo[i];

		visited[u] = true;

		for (int v : adj[u]) {
			if (visited[v] == false)
				continue;

			fill(visited + 1, visited + n + 1, false);

			trace(v, u);

			reverse(path.begin(), path.end());
			path.push_back(v);

			cout << path.size() << '\n';

			for (int u : path) {
				cout << u << ' ';
			}

			return 0;
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}
