// Problem: Flight Routes Check
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1682
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

const int N = 1e5;

vector<int> adj[N + 1];

int num[N + 1];
int low[N + 1];
int scc_id[N + 1];
stack<int> st;

void dfs(int u) {
	static int time = 1;
	num[u] = low[u] = time++;
	st.push(u);

	for (int v : adj[u]) {
		if (scc_id[v] != 0)
			continue;

		if (num[v] == 0) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else {
			low[u] = min(low[u], num[v]);
		}
	}

	if (low[u] == num[u]) {
		static int scc = 0;
		scc++;
			
		int v;
		do {
			v = st.top();
			st.pop();
			scc_id[v] = scc;
		}
		while (u != v);
	}
}

bool visited[N + 1];

bool reachable(int u, int t) {
	if (u == t)
		return true;

	if (visited[u])
		return false;

	visited[u] = true;

	for (int v : adj[u]) {
		if (reachable(v, t))
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
		if (num[u] != 0)
			continue;
		dfs(u);
	}

	int scc = *max_element(scc_id + 1, scc_id + n + 1);

	if (scc == 1) {
		cout << "YES";
		return 0;
	}

	cout << "NO\n";

	int u = max_element(scc_id + 1, scc_id + n + 1) - scc_id;
	int v = min_element(scc_id + 1, scc_id + n + 1) - scc_id;

	if (reachable(v, u))
		cout << u << ' ' << v;
	else
		cout << v << ' ' << u;

	return 0;
}
