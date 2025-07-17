// Problem: Mountain Range
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/3314
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <execution>
using namespace std;

const int N = 2e5;
const int INF = 1e9;

int a[N + 1];

int li[N + 1];
int ri[N + 1];

pair <int, int> sorted[N + 1];
int dp[N + 1];

void calc_l(int n) {
	stack <int> st;

	for (int i = 1; i <= n; i++) {
		while (st.empty() == false && a[st.top()] <= a[i]) {
			st.pop();
		}

		li[i] = (st.empty() ? 0 : st.top());
		st.push(i);
	}
}

void calc_r(int n) {
	stack <int> st;

	for (int i = n; i >= 1; i--) {
		while (st.empty() == false && a[st.top()] <= a[i]) {
			st.pop();
		}

		ri[i] = (st.empty() ? n + 1 : st.top());
		st.push(i);
	}
}

void calc_lr(int n) {
	calc_l(n);
	calc_r(n);
}

void sort(int n) {
	for (int i = 1; i <= n; i++) {
		sorted[i] = {a[i], i};
	}

	sort(sorted + 1, sorted + n + 1);
}

void calc_dp(int n) {
	calc_lr(n);
	sort(n);

	for (int k = n; k >= 1; k--) {
		int i = sorted[k].second;

		dp[i] = 1;

		int l = li[i];
		if (l >= 1)
			dp[i] = max(dp[i], dp[l] + 1);

		int r = ri[i];
		if (r <= n)
			dp[i] = max(dp[i], dp[r] + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	calc_dp(n);

	cout << *max_element(dp + 1, dp + n + 1);

	return 0;
}
