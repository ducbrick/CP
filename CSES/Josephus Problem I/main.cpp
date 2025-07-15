// Problem: Josephus Problem I
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2162
// Memory Limit: 512
// Time Limit: 1000
// By DUCBRICK

#include <bits/stdc++.h>
#include <exception>
using namespace std;

struct LL {
	int v;
	LL* next;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	LL* begin = NULL;
	LL* end = NULL;

	for (int i = 1; i <= n; i++) {
		LL* curr = new LL();

		curr -> v = i;

		if (end == NULL) {
			begin = end = curr;
		}
		else {
			end -> next = curr;
			end = curr;
		}
	}

	end -> next = begin;

	LL* curr = begin;

	for (int i = 1; i <= n; i++) {
		LL* remove = curr -> next;

		cout << remove -> v << ' ';

		curr -> next = remove -> next;
		curr = curr -> next;
	}

	return 0;
}
