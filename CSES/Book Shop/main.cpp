// Problem: Book Shop
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1158
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int X = 1e5;

int price[N + 1];
int pages[N + 1];
int cnt[X + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;

	for (int i = 1; i <= n; i++)
		cin >> price[i];

	for (int i = 1; i <= n; i++)
		cin >> pages[i];

	for (int i = 1; i <= n; i++) {
		for (int p = x; p >= price[i]; p--) {
			cnt[p] = max(cnt[p], cnt[p - price[i]] + pages[i]);
		}
	}

	cout << cnt[x];
	return 0;
}
