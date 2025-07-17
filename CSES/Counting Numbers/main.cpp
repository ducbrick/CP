// Problem: Counting Numbers
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2220
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <cstdint>
#include <cstring>
using namespace std;

const int DIGITS = 19;

int a_digits[DIGITS];
int b_digits[DIGITS];

int64_t f[DIGITS][10][2][2][2];

int digitize(int64_t n, int* digits) {
	for (int i = 0; i < DIGITS; i++) {
		digits[i] = n % 10;
		n /= 10;
		
		if (n == 0)
			return i + 1;
	}

	return DIGITS;
}

int64_t dp(int i, int last_digit, bool started, bool greater_a, bool less_b) {
	if (i < 0)
		return 1;

	int64_t& res = f[i][last_digit][started][greater_a][less_b];

	if (res != -1)
		return res;

	res = 0;

	for (int curr_digit = 0; curr_digit < 10; curr_digit++) {
		if (started && curr_digit == last_digit)
			continue;

		if (greater_a == false && curr_digit < a_digits[i])
			continue;

		if (less_b == false && curr_digit > b_digits[i])
			continue;

		bool next_greater_a = greater_a || (curr_digit > a_digits[i]);
		bool next_less_b = less_b || (curr_digit < b_digits[i]);
		bool next_started = started || (curr_digit > 0);

		res += dp(i - 1, curr_digit, next_started, next_greater_a, next_less_b);
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int64_t a, b;
	cin >> a >> b;

	int n = max(digitize(a, a_digits), digitize(b, b_digits));

	if (n == 0) {
		cout << 1;
		return 0;
	}

	memset(f, -1, sizeof(f));

	cout << dp(DIGITS - 1, 0, false, false, false);

	return 0;
}
