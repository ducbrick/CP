// Problem: Removing Digits
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1637
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int INF = 1e9;

int cnt[N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	fill(cnt, cnt + n + 1, INF);
	cnt[n] = 0;

	for (int v = n; v > 0; v--) {
		if (cnt[v] == INF)
			continue;

		for (int tmp = v; tmp > 0; tmp /= 10) {
			int d = tmp % 10;

			cnt[v - d] = min(cnt[v - d], cnt[v] + 1);
		}
	}

	cout << cnt[0];

	return 0;
}
