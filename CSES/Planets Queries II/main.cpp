// Problem: Planets Queries II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1160
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct Branch_Info {
	int dist_to_cycle;
	int cycle_s;
};

struct Cycle_Part_Info {
	int cycle_id;
	int index;
};

const int N = 2e5;
const int K = 18;

vector<int> parents[N + 1];
int nxt[N + 1][K + 1];

bool visited[N + 1];

int get_cycle_s(int s) {
	for (; visited[s] == false; s = nxt[s][0]) {
		visited[s] = true;
	}
	return s;
}

vector<int> cycles[N + 1];
Cycle_Part_Info cycle_part_infos[N + 1];
Branch_Info branch_infos[N + 1];

void set_branch_infos(int u, int dist_to_cycle, int cycle_s) {
	visited[u] = true;
	branch_infos[u] = {dist_to_cycle, cycle_s};

	for (int p : parents[u]) {
		if (cycle_part_infos[p].cycle_id != 0)
			continue;

		set_branch_infos(p, dist_to_cycle + 1, cycle_s);
	}
}

void process_cycle(int s) {
	static int cycle_id = 0;
	cycle_id++;

	vector<int> &cycle = cycles[cycle_id];

	int u = s;

	while (true) {
		cycle_part_infos[u] = {cycle_id, (int) cycle.size()};
		cycle.push_back(u);

		u = nxt[u][0];

		if (u == s)
			break;
	}

	for (int u : cycle) {
		set_branch_infos(u, 0, u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	for (int u = 1; u <= n; u++) {
		int &v = nxt[u][0];
		cin >> v;
		parents[v].push_back(u);
	}

	for (int k = 1; k <= K; k++) 
		for (int u = 1; u <= n; u++) {
			int v = nxt[u][k - 1];
			nxt[u][k] = nxt[v][k - 1];
		}

	for (int u = 1; u <= n; u++) {
		if (visited[u])
			continue;

		int cycle_s = get_cycle_s(u);
		process_cycle(cycle_s);
	}

	while (q--) {
		int u, v;
		cin >> u >> v;

		if (branch_infos[u].dist_to_cycle < branch_infos[v].dist_to_cycle) {
			cout << -1 << '\n';
			continue;
		}

		int res = 0;

		while (branch_infos[u].dist_to_cycle > branch_infos[v].dist_to_cycle) {
			int diff = branch_infos[u].dist_to_cycle - branch_infos[v].dist_to_cycle;
			int k = log2(diff);
			u = nxt[u][k];
			res += (1 << k);
		}

		int cycle_s_u = branch_infos[u].cycle_s;
		int cycle_s_v = branch_infos[v].cycle_s;
		auto [cycle_id, index_u] = cycle_part_infos[cycle_s_u];
		int index_v = cycle_part_infos[cycle_s_v].index;
		
		if (cycle_part_infos[cycle_s_v].cycle_id != cycle_id) {
			cout << -1 << '\n';
			continue;
		}

		if (branch_infos[v].dist_to_cycle > 0 && u != v) {
			cout << -1 << '\n';
			continue;
		}

		vector<int> &cycle = cycles[cycle_id];

		res += (index_v - index_u + cycle.size()) % cycle.size();

		cout << res << '\n';
	}

	return 0;
}
