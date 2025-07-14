// Problem: Restaurant Customers
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1619
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

pair <int, int> events[2 * MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;

		events[2 * i] = {a, 1};
		events[2 * i + 1] = {b + 1, -1};
	}

	sort(events + 1, events + 2 * n + 1);

	int res = 0;
	int cnt = 0;

	for (int i = 1; i <= 2 * n; i++) {
		cnt += events[i].second;
		res = max(res, cnt);
	}

	cout << res;

	return 0;
}
