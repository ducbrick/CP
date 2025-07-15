// Problem: Nested Ranges Check
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2168
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <climits>
using namespace std;

const int MAX_N = 2e5;

struct Range {
	int l;
	int r;
	int id;
};

Range ranges[MAX_N + 1];

bool contain[MAX_N + 1];
bool contained[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		auto &[l, r, id] = ranges[i];
		cin >> l >> r;
		id = i;
	}

	sort(ranges + 1, ranges + n + 1, [](Range &a, Range &b) {
		if (a.l != b.l)
			return (a.l < b.l);

		return (a.r > b.r);
	});

	int min_r = INT_MAX;

	for (int i = n; i >= 1; i--) {
		auto [l, r, id] = ranges[i];

		contain[id] = (min_r <= r);
		min_r = min(min_r, r);
	}

	int max_r = INT_MIN;

	for (int i = 1; i <= n; i++) {
		auto [l, r, id] = ranges[i];

		contained[id] = (max_r >= r);
		max_r = max(max_r, r);
	}

	for (int i = 1; i <= n; i++) {
		cout << contain[i] << ' ';
	}

	cout << '\n';

	for (int i = 1; i <= n; i++) {
		cout << contained[i] << ' ';
	}

	return 0;
}
