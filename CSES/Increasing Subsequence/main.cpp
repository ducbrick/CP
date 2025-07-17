// Problem: Increasing Subsequence
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1145
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

const int N = 2e5;

int a[N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector <int> tails;

	for (int i = 1; i <= n; i++) {
		if (tails.empty() || tails.back() < a[i])
			tails.push_back(a[i]);

		else
			*lower_bound(tails.begin(), tails.end(), a[i]) = a[i];
	}

	cout << tails.size();

	return 0;
}
