// Problem: Building Teams
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1668
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 1e5;

vector<int> adj[N + 1];
int team[N + 1];

void dfs(int u, int t) {
	if (team[u] == t) {
		return;
	}

	if (team[u] != 0 && team[u] != t) {
		cout << "IMPOSSIBLE";
		exit(0);
	}

	team[u] = t;

	for (int v : adj[u]) {
		dfs(v, 1 ^ 2 ^ t);
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
		if (team[u] != 0) {
			continue;
		}

		dfs(u, 1);
	}

	for (int u = 1; u <= n; u++) {
		cout << team[u] << ' ';
	}

	return 0;
}
