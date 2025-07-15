// Problem: Traffic Lights
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1163
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, n;
	cin >> x >> n;

	multiset <int> lengths;
	multiset <int> positions;

	lengths.insert(x);
	positions.insert(0);
	positions.insert(x);

	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;

		auto it = positions.upper_bound(p);

		int r = *it;
		int l = *(--it);

		lengths.erase(lengths.find(r - l));

		positions.insert(p);
		lengths.insert(p - l);
		lengths.insert(r - p);

		it = lengths.end();
		it--;

		cout << *it << ' ';
	}

	return 0;
}
