// Problem: Message Route
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1667
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector <int> adj[N + 1];
int dist[N + 1];
int parent[N + 1];

void bfs(int s) {
	queue <int> q;

	dist[s] = 1;
	q.push(s);

	while (q.empty() == false) {
		int u = q.front();
		q.pop();

		for (int v : adj[u]) {
			if (dist[v] > 0)
				continue;

			parent[v] = u;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
}

void trace(int u) {
	if (dist[u] > 1)
		trace(parent[u]);

	cout << u << ' ';
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

	int s = 1;
	int t = n;

	bfs(s);

	if (dist[t] == 0) {
		cout << "IMPOSSIBLE";
		return 0;
	}

	cout << dist[t] << '\n';

	trace(t);

	return 0;
}
