#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

const int N = 1e5;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		cout << (n % 4 == 0 ? "false" : "true") << '\n';
	}
}
