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

struct Max_seqtree {
	int tree_l;
	int tree_r;
	int v;
	Max_seqtree* l_tree;
	Max_seqtree* r_tree;

	Max_seqtree(int l, int r) {
		tree_l = l;
		tree_r = r;

		if (l == r) {
			v = -INF;
			l_tree = NULL;
			r_tree = NULL;
			return;
		}

		int m = (l + r) / 2;

		l_tree = new Max_seqtree(l, m);
		r_tree = new Max_seqtree(m + 1, r);

		v = max(l_tree->v, r_tree->v);
	}

	void update(int i, int new_v) {
		if (tree_r < i || i < tree_l)
			return;

		if (tree_l == tree_r) {
			v = new_v;
			return;
		}

		l_tree->update(i, new_v);
		r_tree->update(i, new_v);

		v = max(l_tree->v, r_tree->v);
	}

	int get(int l, int r) {
		if (tree_r < l || r < tree_l)
			return -INF;

		if (l <= tree_l && tree_r <= r)
			return v;

		return max(l_tree->get(l, r), r_tree->get(l, r));
	}
};

int a[N + 1];

int li[N + 1];
int ri[N + 1];

pair <int, int> sorted[N + 1];
int dp[N + 1];

void calc_l(int n) {
	stack <int> st;

	for (int i = 1; i <= n; i++) {
		while (st.empty() == false && a[st.top()] < a[i]) {
			st.pop();
		}

		li[i] = (st.empty() ? 0 : st.top());
		st.push(i);
	}
}

void calc_r(int n) {
	stack <int> st;

	for (int i = n; i >= 1; i--) {
		while (st.empty() == false && a[st.top()] < a[i]) {
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

	Max_seqtree* seqtree = new Max_seqtree(1, n);

	for (int k = 1; k <= n; k++) {
		int i = sorted[k].second;

		dp[i] = 1;

		int l = li[i];
		dp[i] = max(dp[i], seqtree->get(l + 1, i - 1) + 1);

		int r = ri[i];
		dp[i] = max(dp[i], seqtree->get(i + 1, r - 1) + 1);

		seqtree->update(i, dp[i]);
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
