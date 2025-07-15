// Problem: Room Allocation
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1164
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>
using namespace std;

const int MAX_N = 2e5;

tuple <int, int, int> events[MAX_N + 1];
int res[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		auto &[l, r, id] = events[i];
		cin >> l >> r;
		id = i;
	}

	sort(events + 1, events + n + 1);

	set <pair <int, int>> q;
	int cnt = 1;

	q.insert({INT_MIN, 0});
	res[0] = 1;

	for (int i = 1; i <= n; i++) {
		auto [l, r, id] = events[i];

		auto [min_r, last_id] = *q.begin();

		if (min_r < l) {
			q.erase(q.begin());
			res[id] = res[last_id];
		}
		else {
			cnt++;
			res[id] = cnt;
		}

		q.insert({r, id});
	}

	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
	}

	return 0;
}
