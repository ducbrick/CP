// Problem: Labyrinth
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1193
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <queue>
#include <variant>
#include <vector>
using namespace std;

const int NM = 1000;

char c[NM + 1][NM + 1];
int dist[NM + 1][NM + 1];
pair <int, int> prev_tiles[NM + 1][NM + 1];

bool is_wall(pair <int, int> p) {
	auto [i, j] = p;
	return c[i][j] == '#';
}

pair <int, int> get_prev(pair <int, int> p) {
	auto [i, j] = p;
	return prev_tiles[i][j];
}

void set_prev(pair <int, int> p, pair <int, int> prev_tile) {
	auto [i, j] = p;
	prev_tiles[i][j] = prev_tile;
}

int get_dist(pair <int, int> p) {
	auto [i, j] = p;
	return dist[i][j];
}

void set_dist(pair <int, int> p, int d) {
	auto [i, j] = p;
	dist[i][j] = d;
}

vector <pair <int, int>> get_adj(pair <int, int> p) {
	vector <pair <int, int>> res;

	vector <pair <int, int>> dirs = {
		{1, 0},
		{-1, 0},
		{0, 1},
		{0, -1}
	};

	auto [i, j] = p;

	for (auto [dir_i, dir_j] : dirs) {
		pair <int, int> q = {i + dir_i, j + dir_j};
		res.push_back(q);
	}

	return res;
}

bool out_of_bound(pair <int, int> p, int n, int m) {
	auto [i, j] = p;
	return (i < 1 || i > n || j < 1 || j > m);
}

int bfs(pair <int, int> initial , int n, int m) {
	queue <pair <int, int>> que;

	set_dist(initial, 1);
	que.push(initial);

	while (que.empty() == false) {
		auto p = que.front();
		que.pop();

		for (auto q : get_adj(p)) {
			if (out_of_bound(q, n, m))
				continue;

			if (is_wall(q))
				continue;

			if (get_dist(q) != 0)
				continue;

			set_dist(q, get_dist(p) + 1);
			set_prev(q, p);
			que.push(q);
		}
	}

	return 1;
}

char get_dir_char(pair <int, int> p) {
	auto [i, j] = p;
	auto [pi, pj] = prev_tiles[i][j];

	int dir_i = i - pi;
	int dir_j = j - pj;

	if (dir_i == 0 && dir_j == 1)
		return 'R';

	if (dir_i == 0 && dir_j == -1)
		return 'L';

	if (dir_i == 1 && dir_j == 0)
		return 'D';

	return 'U';
}

void trace(pair <int, int> p, pair <int, int> start) {
	if (p == start)
		return;

	trace(get_prev(p), start);
	cout << get_dir_char(p);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	pair <int, int> start;
	pair <int, int> end;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];

			if (c[i][j] == 'A')
				start = {i, j};

			if (c[i][j] == 'B')
				end = {i, j};
		}
	}

	bfs(start, n, m);

	if (get_dist(end) == 0) {
		cout << "NO";
		return 0;
	}

	cout << "YES" << '\n';
	cout << get_dist(end) - 1 << '\n';

	trace(end, start);

	return 0;
}
