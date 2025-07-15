// Problem: Nested Ranges Count
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2169
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdarg>
#include <locale>
using namespace std;

const int MAX_N = 2e5;
const int MAX_LIM = 2 * MAX_N;

struct Range {
	int l;
	int r;
	int id;
};

Range ranges[MAX_N + 1];

int compress(int n) {
	vector <int> values;

	for (int i = 1; i <= n; i++) {
		auto [l, r, id] = ranges[i];
		values.push_back(l);
		values.push_back(r);
	}

	sort(values.begin(), values.end());

	int lim = 0;

	for (int i = 1; i <= n; i++) {
		auto &[l, r, id] = ranges[i];

		l = lower_bound(values.begin(), values.end(), l) - values.begin() + 1;
		r = lower_bound(values.begin(), values.end(), r) - values.begin() + 1;

		lim = max(lim, r);
	}

	return lim;
}

int bit[MAX_LIM + 1];

void update(int i, int v) {
	for (; i <= MAX_LIM; i += i & (-i)) {
		bit[i] += v;
	}
}

int get(int i) {
	int res = 0;

	for (; i > 0; i -= i & (-i)) {
		res += bit[i];
	}

	return res;
}

int contain[MAX_N + 1];
int contained[MAX_N + 1];

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

	compress(n);

	sort(ranges + 1, ranges + n + 1, [](Range &a, Range &b) {
		if (a.l != b.l)
			return (a.l < b.l);

		return (a.r > b.r);
	});

	fill(bit, bit + MAX_LIM + 1, 0);

	for (int i = n; i >= 1; i--) {
		auto [l, r, id] = ranges[i];

		contain[id] = get(r) - get(l - 1);
		update(r, 1);
	}

	fill(bit, bit + MAX_LIM + 1, 0);

	for (int i = 1; i <= n; i++) {
		auto [l, r, id] = ranges[i];

		contained[id] = get(MAX_LIM) - get(r - 1);
		update(r, 1);
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
