#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

bool f(int n, int64_t k) {
	if (n == 1)
		return true;

	int64_t len = (1LL << (n - 1));
	int64_t half = len / 2;

	return (k <= half ? f(n - 1, k) : !f(n - 1, k - half));
}

char solve() {
	int n;
	cin >> n;

	int64_t k;
	cin >> k;

	return f(n, k) ? 'X' : 'Y';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}
}
