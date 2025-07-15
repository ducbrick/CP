// Problem: Movie Festival II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1632
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

pair <int, int> movies[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		auto &[start, end] = movies[i];
		cin >> start >> end;
	}

	multiset <int> q;

	sort(movies + 1, movies + n + 1);

	int res = 0;

	for (int i = 1; i <= n; i++) {
		auto [start, end] = movies[i];

		if (q.size() < k) {
			q.insert(end);
			continue;
		}

		if (*q.begin() <= start) {
			res++;
			q.erase(q.begin());

			q.insert(end);
			continue;
		}

		auto it = q.end();
		it--;

		int max_end = *it;

		if (end < max_end) {
			q.erase(it);
			q.insert(end);
		}
	}

	res += q.size();

	cout << res;

	return 0;
}
