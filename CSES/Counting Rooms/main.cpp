// Problem: Counting Rooms
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1192
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
bool visited[NM + 1][NM + 1];

bool is_wall(pair <int, int> p) {
	auto [i, j] = p;
	return c[i][j] == '#';
}

bool is_visited(pair <int, int> p) {
	auto [i, j] = p;
	return visited[i][j];
}

void visit(pair <int, int> p) {
	auto [i, j] = p;
	visited[i][j] = true;
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

int bfs(int i, int j, int n, int m) {
	pair <int, int> initial = {i, j};

	if (is_wall(initial))
		return 0;

	if (is_visited(initial))
		return 0;

	queue <pair <int, int>> que;

	visit(initial);
	que.push(initial);

	while (que.empty() == false) {
		auto p = que.front();
		que.pop();

		for (auto q : get_adj(p)) {
			if (out_of_bound(q, n, m))
				continue;

			if (is_wall(q))
				continue;

			if (is_visited(q))
				continue;

			visit(q);
			que.push(q);
		}
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
	}

	int res = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			res += bfs(i, j, n, m);
		}
	}

	cout << res;

	return 0;
}
