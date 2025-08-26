// Problem: C. The Nether
// Contest: Codeforces Round 1044 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2133/problem/C
// Memory Limit: 256
// Time Limit: 3000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int query(vector<int>& nodes, int s) {
	cout << '?' << ' ';
	cout << s << ' ';
	cout << nodes.size() << ' ';

	for (int u : nodes) {
		cout << u << ' ';
	}

	cout << endl;

	int res;
	cin >> res;

	return res;
}

void answer(vector<int>& nodes) {
	cout << '!' << ' ';
	cout << nodes.size() << ' ';

	for (int u : nodes) {
		cout << u << ' ';
	}

	cout << endl;
}

const int N = 500;

vector<int> nodes_for_d[N + 1];

void solve() {
	int n;
	cin >> n;

	vector<int> full;

	for (int u = 1; u <= n; u++) {
		nodes_for_d[u].clear();
		full.push_back(u);
	}

	int max_d = 1;

	for (int u = 1; u <= n; u++) {
		int d = query(full, u);
		nodes_for_d[d].push_back(u);
		max_d = max(max_d, d);
	}
	
	vector<int> res;

	int u = nodes_for_d[max_d].front();

	res.push_back(u);

	for (int d = max_d; d > 0; d--) {
		for (int v : nodes_for_d[d - 1]) {
			vector<int> nodes = {u, v};

			if (query(nodes, u) == 1) {
				continue;
			}

			res.push_back(v);
			u = v;
			break;
		}
	}

	answer(res);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
