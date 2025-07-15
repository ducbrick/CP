// Problem: Sum of Four Values
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1642
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;

pair <int64_t, int> a[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; i++) {
		auto &[value, index] = a[i];
		cin >> value;
		index = i;
	}

	sort(a + 1, a + n + 1);

	map <int64_t, pair <int, int>> f;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			auto [value_i, index_i] = a[i];
			auto [value_j, index_j] = a[j];

			if (f.count(x - value_i - value_j) == false)
				continue;

			auto [index_k, index_l] = f[x - value_i - value_j];
			
			cout 
				<< index_i	<< ' '
				<< index_j	<< ' '
				<< index_k	<< ' '
				<< index_l	<< ' ';
			return 0;
		}

		for (int j = 1; j < i; j++) {
			auto [value_i, index_i] = a[i];
			auto [value_j, index_j] = a[j];

			f[value_i + value_j] = {index_i, index_j};
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}
