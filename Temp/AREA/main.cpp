#include <bits/stdc++.h>
#include <cstdint>
#include <stack>
using namespace std;

const int NM = 2000;

bool a[NM + 1][NM + 1];

int h[NM + 1];
int l[NM + 1];
int r[NM + 1];

void calc_h(int n, int j) {
	for (int i = 1; i <= n; i++) {
		h[i] = (a[i][j] ? h[i] + 1 : 0);
	}
}

void calc_l(int n, int j) {
	stack <int> st;

	for (int i = 1; i <= n; i++) {
		while (st.empty() == false && h[st.top()] >= h[i]) {
			st.pop();
		}

		l[i] = st.empty() ? 0 : st.top();
		st.push(i);
	}
}

void calc_r(int n, int j) {
	stack <int> st;

	for (int i = n; i >= 1; i--) {
		while (st.empty() == false && h[st.top()] >= h[i]) {
			st.pop();
		}

		r[i] = st.empty() ? n + 1 : st.top();
		st.push(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}

	int res = 0;

	for (int j = 1; j <= m; j++) {
		calc_h(n, j);
		calc_l(n, j);
		calc_r(n, j);
		
		for (int i = 1; i <= n; i++) {
			res = max(res, h[i] * (r[i] - l[i] - 1));
		}
	}

	cout << res;
}
