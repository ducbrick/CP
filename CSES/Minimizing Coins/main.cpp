// Problem: Minimizing Coins
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1634
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
const int MAX_X = 1e6;
const int INF = 1e9;

int coin[MAX_N + 1];
int cnt[MAX_X + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	fill(cnt, cnt + x + 1, INF);
	cnt[0] = 0;

	for (int v = 1; v <= x; v++)
		for (int i = 1; i <= n; i++)
			if (v - coin[i] >= 0)
				cnt[v] = min(cnt[v], cnt[v - coin[i]] + 1);

	cout << ( cnt[x] == INF ? -1 : cnt[x] );

	return 0;
}
