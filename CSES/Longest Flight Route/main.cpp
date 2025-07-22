// Problem: Longest Flight Route
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1680
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 1e5;
const int INF = 1e9;

vector<int> adj[N + 1];

bool visited[N + 1];
int topo[N + 1];

int f[N + 1];
int p[N + 1];

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

	int s = 1;
	int t = n;

	fill(f + 1, f + n + 1, -INF);

	p[s] = -1;
	f[s] = 1;

	for (int i = 1; i <= n; i++) {
		int u = topo[i];

		if (f[u] == -INF)
			continue;

		for (int v : adj[u]) {
			if (f[u] + 1 <= f[v])
				continue;

			f[v] = f[u] + 1;
			p[v] = u;
		}
	}

	if (f[t] == -INF) {
		cout << "IMPOSSIBLE";
		return 0;
	}

	vector<int> path;

	while (t != -1) {
		path.push_back(t);
		t = p[t];
	}

	reverse(path.begin(), path.end());

	cout << path.size() << '\n';

	for (int u : path) {
		cout << u << ' ';
	}

	return 0;
}
