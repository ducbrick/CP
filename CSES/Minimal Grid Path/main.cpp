// Problem: Minimal Grid Path
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3359
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <variant>
using namespace std;

const int N = 3000;

char a[N + 1][N + 1];
bool visited[N + 1][N + 1];

char out_of_bound(pair <int, int> pos, int n) {
	auto [i, j] = pos;
	return (i < 1 || i > n || j < 1 || j > n);
}

char get(pair <int, int> pos) {
	auto [i, j] = pos;
	return a[i][j];
}

bool is_visited(pair <int, int> pos) {
	auto [i, j] = pos;
	return visited[i][j];
}

void visit(pair <int, int> pos) {
	auto [i, j] = pos;
	visited[i][j] = true;
}

vector <pair <int, int>> get_adj(pair <int, int> pos) {
	auto [i, j] = pos;
	return {{i + 1, j}, {i, j + 1}};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	vector <pair <int, int>> curr_q;
	vector <pair <int, int>> next_q;

	curr_q.push_back({1, 1});

	for (int step = 1; step <= n + n - 1; step++) {
		char curr_c = get(curr_q.front());
		cout << curr_c;

		char next_c = 'Z';

		for (auto curr_p : curr_q) {
			for (auto next_p : get_adj(curr_p)) {
				if (out_of_bound(next_p, n))
					continue;

				next_c = min(next_c, get(next_p));
			}
		}

		next_q.clear();

		for (auto curr_p : curr_q) {
			for (auto next_p : get_adj(curr_p)) {
				if (out_of_bound(next_p, n))
					continue;

				if (get(next_p) != next_c)
					continue;

				if (is_visited(next_p))
					continue;

				visit(next_p);

				next_q.push_back(next_p);
			}
		}

		swap(curr_q, next_q);
	}

	return 0;
}
