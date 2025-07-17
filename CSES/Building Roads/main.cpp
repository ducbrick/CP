// Problem: Building Roads
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1666
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector <int> adj[N + 1];
bool visited[N + 1];

void dfs(int u) {
	if (visited[u])
		return;

	visited[u] = true;

	for (int v : adj[u]) {
		dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector <int> cp;

	for (int u = 1; u <= n; u++) {
		if (visited[u])
			continue;

		cp.push_back(u);
		dfs(u);
	}

	cout << cp.size() - 1 << '\n';

	for (int i = 1; i < cp.size(); i++) {
		int u = cp[i];
		int v = cp[i - 1];

		cout << u << ' ' << v << '\n';
	}

	return 0;
}
