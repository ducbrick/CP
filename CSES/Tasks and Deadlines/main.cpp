// Problem: Tasks and Deadlines
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1630
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int MAX_N = 2e5;

pair <int, int> a[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		auto &[duration, deadline] = a[i];
		cin >> duration >> deadline;
	}

	sort(a + 1, a + n + 1);

	int64_t res = 0;
	int64_t time = 0;

	for (int i = 1; i <= n; i++) {
		auto [duration, deadline] = a[i];

		time += duration;
		res += deadline - time;
	}

	cout << res;

	return 0;
}
