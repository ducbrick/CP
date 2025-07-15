// Problem: Nearest Smaller Values
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1645
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	stack <pair <int, int>> st;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		while (st.empty() == false && st.top().first >= a) {
			st.pop();
		}

		cout << (st.empty() ? 0 : st.top().second) << ' ';
		st.push({a, i});
	}

	return 0;
}
