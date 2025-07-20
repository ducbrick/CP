#include <bits/stdc++.h>
#include <cstdint>
#include <stack>
using namespace std;

typedef vector <int64_t> vi;
typedef vector <vi> vii;

const int SIZE = 5;
const int MOD = 1e9 + 7;
const vii BASE = {
			{0, 1, 0, 0, 0},
			{1, 0, 1, 0, 0},
			{1, 1, 0, 1, 1},
			{0, 0, 1, 0, 1},
			{1, 0, 0, 0, 0},
};
const vii IDENTITY = {
			{1, 0, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 0, 1, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 0, 1},
};

vii multiply(vii a, vii b) {
	vii res = vii(SIZE, vi(SIZE, 0));

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			for (int k = 0; k < SIZE; k++) {
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= MOD;
			}

	return res;
}

vii power(vii a, int64_t n) {
	vii res = IDENTITY;

	for ( ; n > 0; n /= 2) {
		if (n % 2) {
			res = multiply(res, a);
		}

		a = multiply(a, a);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int64_t n;
	cin >> n;

	vi f = {1, 1, 1, 1, 1};

	vii matrix = power(BASE, n - 1);

	int64_t res = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			res += f[j] * matrix[i][j];
			res %= MOD;
		}
	}

	cout << res;
}

//
// 0 = Hong
// 1 = Li
// 2 = Mai
// 3 = Lan
// 4 = Tulip
//
//         0 1 2 3 4
// f[0] = [0 1 0 0 0]
// f[1] = [1 0 1 0 0]
// f[2] = [1 1 0 1 1]
// f[3] = [0 0 1 0 1]
// f[4] = [1 0 0 0 0]
