// Problem: Towers
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1073
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector <int> lis;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;

		if (lis.empty() || lis.back() <= a) {
			lis.push_back(a);
		}
		else {
			*upper_bound(lis.begin(), lis.end(), a) = a;
		}
	}

	cout << lis.size();

	return 0;
}
