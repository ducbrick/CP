// Problem: Distinct Numbers
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1621
// Memory Limit: 512
// Time Limit: 1000
// Start: Mon 14 Jul 2025 10:54:42 PM +07
// By DUCBRICK

#include <bits/stdc++.h>
#include <set>
using namespace std;

int main() {
	set<int> cnt;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		cnt.insert(a);
	}

	cout << cnt.size();
	return 0;
}
