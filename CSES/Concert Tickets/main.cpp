// Problem: Concert Tickets
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1091
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	multiset <int> tickets;

	for (int i = 1; i <= n; i++) {
		int ticket;
		cin >> ticket;
		tickets.insert(ticket);
	}

	for (int i = 1; i <= m; i++) {
		int maxPrice;
		cin >> maxPrice;

		auto it = tickets.upper_bound(maxPrice);

		if (it == tickets.begin()) {
			cout << -1 << ' ';
			continue;
		}

		it--;

		cout << *it << ' ';
		tickets.erase(it);
	}

	return 0;
}
