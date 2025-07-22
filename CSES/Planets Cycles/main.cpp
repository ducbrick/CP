// Problem: Planets Cycles
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1751
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
int nxt[N + 1];
 
bool visited[N + 1];
 
int get_cycle_s(int s) {
	for (; visited[s] == false; s = nxt[s]) {
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
 
		u = nxt[u];
 
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
 
	int n;
	cin >> n;
 
	for (int u = 1; u <= n; u++) {
		int &v = nxt[u];
		cin >> v;
		parents[v].push_back(u);
	}
 
	for (int u = 1; u <= n; u++) {
		if (visited[u])
			continue;
 
		int cycle_s = get_cycle_s(u);
		process_cycle(cycle_s);
	}
 
	for (int u = 1; u <= n; u++) {
		auto [dist_to_cycle, cycle_s] = branch_infos[u];
 
		auto cycle_id = cycle_part_infos[cycle_s].cycle_id;
 
		vector<int> &cycle = cycles[cycle_id];
 
		int cycle_size = cycle.size();
 
		int res = dist_to_cycle + cycle_size;
		cout << res << ' ';
	}
	return 0;
}
