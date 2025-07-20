#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int N = 1e5;

int64_t s[N + 2];
int64_t dp[N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	if (k <= 0) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] += s[i - 1];
	}

	multiset <int64_t> q;
	
	for (int r = 1; r <= n; r++) {
		q.insert(dp[r - 1] - s[r]);
		
		if (r - k - 2 >= 0) {
			int l = r - k - 2;
			q.erase(q.find(dp[l] - s[l + 1]));
		}

		dp[r] = dp[r - 1];

		if (q.empty() == false) {
			auto it = q.end();
			it--;
			
			int64_t v = *it;
			dp[r] = max(dp[r], s[r] + v);
		}

		if (r <= k) {
			dp[r] = max(dp[r], s[r]);
		}
	}

	cout << dp[n];
}

// s[R] - s[L + 1] + dp[L]
// R - L - 1 <= k
// L >= R - k - 1
//
// s[R] max
// dp[L] - s[L + 1] max
