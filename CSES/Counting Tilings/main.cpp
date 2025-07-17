// Problem: Counting Tilings
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2181
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <bitset>
#include <regex>
#include <vector>
using namespace std;

const int N = 10;
const int M = 1000;
const int MASK = (1 << N) - 1;
const int MOD = 1e9 + 7;

int f[M + 1][MASK + 1];
vector<int> valid_submask[MASK + 1];

bool bit_on(int mask, int i) {
	return (((mask >> i) & 1) == 1);
}

int invert_mask(int mask_a, int mask_b) {
	return mask_a ^ mask_b;
}

bool is_valid_submask(int submask, int n) {
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (bit_on(submask, i)) {
			cnt++;
			continue;
		}

		if (cnt % 2 == 1)
			return false;

		cnt = 0;
	}

	return (cnt % 2 == 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int max_mask = (1 << n) - 1;

	for (int mask = 0; mask <= max_mask; mask++) {
		valid_submask[mask].push_back(0);

		for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
			if (is_valid_submask(submask, n) == false)
				continue;

			valid_submask[mask].push_back(submask);
		}
	}

	f[0][max_mask] = 1;

	for (int i = 1; i <= m; i++) {
		for (int mask = 0; mask <= max_mask; mask++) {
			for (int submask : valid_submask[mask]) {
				int last_i_mask = invert_mask(max_mask, invert_mask(mask, submask));

				f[i][mask] += f[i - 1][last_i_mask];
				f[i][mask] %= MOD;
			}

			// cerr << i << ' ' << bitset<2>(mask) << ' ' << f[i][mask] << endl;
		}
	}

	cout << f[m][max_mask];

	return 0;
}
