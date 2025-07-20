#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
using namespace std;

const int N = 5e5;

vector<int> adj[N];
bool visited[N];

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

	if (m < n - 1) {
		cout << -1;
		return 0;
	}

	while (m--) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int cc = 0;

	for (int u = 0; u < n; u++) {
		if (visited[u])
			continue;

		dfs(u);
		cc++;
	}

	cout << cc - 1;
}
