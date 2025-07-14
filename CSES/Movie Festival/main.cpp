// Problem: Movie Festival
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1629
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5;

pair <int, int> movies[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int start, end;
		cin >> start >> end;

		movies[i] = {start, end};
	}

	sort(movies + 1, movies + n + 1);

	int cnt = 0;
	int prevEnd = INT_MIN;

	for (int i = 1; i <= n; i++) {
		auto [start, end] = movies[i];

		if (prevEnd <= start) {
			cnt++;
			prevEnd = end;
		}

		prevEnd = min(prevEnd, end);
	}

	cout << cnt;

	return 0;
}
