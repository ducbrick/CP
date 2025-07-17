// Problem: Projects
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1140
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int N = 2e5;

struct Event {
	int time;
	int type;
	int id;
};

Event events[2 * N + 1];
int reward[N + 1];
int64_t dp[N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int start, end;
		cin >> start >> end >> reward[i];

		events[2 * i - 1] = {start, 1, i};
		events[2 * i] = {end, -1, i};
	}

	sort(events + 1, events + 2 * n + 1, [] (Event a, Event b) {
		if (a.time != b.time)
			return a.time < b.time;

		return (a.type == 1 && b.type == -1);
	});

	int64_t res = 0;

	for (int i = 1; i <= 2 * n; i++) {
		auto [time, type, id] = events[i];

		if (type == 1) {
			dp[id] = res + reward[id];
		}
		else {
			res = max(res, dp[id]);
		}
	}

	cout << res;
	
	return 0;
}
