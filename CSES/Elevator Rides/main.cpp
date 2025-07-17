// Problem: Elevator Rides
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1653
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int N = 20;
const int MASK = (1 << N) - 1;
const int INF = 1e9;

struct State {
	int cnt;
	int w;
};

int w[N];
State f[MASK + 1];

bool bit_off(int mask, int i) {
	return (mask >> i & 1) == 0;
}

int invert_bit(int mask, int i) {
	return (mask ^ (1 << i));
}

State calc_new(State old, int w, int lim) {
	old.w += w;
	
	if (old.w > lim) {
		old.cnt++;
		old.w = w;
	}

	return old;
}

State min(State a, State b) {
	if (a.cnt != b.cnt)
		return (a.cnt < b.cnt ? a : b);

	return (a.w < b.w ? a : b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}

	int max_mask = (1 << n) - 1;

	f[0] = {0, x};

	for (int mask = 1; mask <= max_mask; mask++) {
		f[mask] = {INF, 0};

		for (int i = 0; i < n; i++) {

			if (bit_off(mask, i))
				continue;

			int prev_mask = invert_bit(mask, i);

			State state = calc_new(f[prev_mask], w[i], x);
			f[mask] = min(f[mask], state);
		}
	}

	cout << f[max_mask].cnt;

	return 0;
}
