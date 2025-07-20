// Problem: Monsters
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1194
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstddef>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

template<typename T, size_t row, size_t col> T& get(T (&matrix)[row][col], pii p) {
	auto [i, j] = p;
	return matrix[i][j];
}

pii operator+(pii a, pii b) {
	return {a.first + b.first, a.second + b.second};
}

pii operator-(pii a, pii b) {
	return {a.first - b.first, a.second - b.second};
}

vector<pii> get_adj(pii u) {
	auto [i, j] = u;
	return {
		{i + 1, j},
		{i - 1, j},
		{i, j + 1},
		{i, j - 1}
	};
}

char get_dir_char(pii dir) {
	auto [i, j] = dir;

	if (i == 1 && j == 0)
		return 'D';

	if (i == -1 && j == 0)
		return 'U';

	if (i == 0 && j == 1)
		return 'R';

	return 'L';
}

const int NM = 1000;
const int INF = 1e9;

char a[NM + 1][NM + 1];
int d_monster[NM + 1][NM + 1];
int d_s[NM + 1][NM + 1];
pii p_s[NM + 1][NM + 1];

bool out_of_bound(pii p, int n, int m) {
	auto [i, j] = p;
	return i < 1 || i > n || j < 1 || j > m;
}

void bfs(vector<pii> s, int (&d)[NM + 1][NM + 1], int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = INF;
		}
	}


	queue<pii> q;

	for (pii u : s) {
		get(d, u) = 0;
		q.push(u);
	}

	while (q.empty() == false) {
		pii u = q.front();
		q.pop();

		for (pii v : get_adj(u)) {
			if (out_of_bound(v, n, m)) {
				continue;
			}

			if (get(a, v) == '#') {
				continue;
			}

			if (get(d, v) != INF) {
				continue;
			}

			get(p_s, v) = u;
			get(d, v) = get(d, u) + 1;
			q.push(v);
		}
	}
}

void trace(pii s, pii t) {
	vector<char> path;

	while (s != t) {
		pii p = get(p_s, t);
		path.push_back(get_dir_char(t - p));
		t = p;
	}

	reverse(path.begin(), path.end());

	cout << path.size() << '\n';

	for (char dir : path) {
		cout << dir;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pii> monsters;
	pii s;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];

			if (a[i][j] == 'A') {
				s = {i, j};
			}
			else if (a[i][j] == 'M') {
				monsters.push_back({i, j});
			}
		}
	}

	bfs(monsters, d_monster, n, m);
	bfs({s}, d_s, n, m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i != 1 && i != n && j != 1 && j != m) {
				continue;
			}

			pii t = {i, j};

			if (get(d_s, t) == INF) {
				continue;
			}

			if (get(d_monster, t) <= get(d_s, t)) {
				continue;
			}

			cout << "YES" << '\n';
			trace(s, t);
			return 0;
		}
	}

	cout << "NO";

	return 0;
}
