// Problem: D. Arboris Contractio
// Contest: Codeforces Round 1042 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2131/problem/D
// Memory Limit: 256
// Time Limit: 2000
// By DUCBRICK

#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 2e5;

vector<int> adj[N + 1];

bool is_leaf(int u) {
	return ((int)adj[u].size() == 1);
}

int solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int leaf = 0;

	for (int u = 1; u <= n; u++) {
		leaf += is_leaf(u);
	}

	int res = leaf - 1;

	for (int u = 1; u <= n; u++) {
		int cnt = leaf - is_leaf(u);

		for (int v : adj[u]) {
			cnt -= is_leaf(v);
		}

		res = min(res, cnt);
	}

	for (int u = 1; u <= n; u++) {
		adj[u].clear();
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
