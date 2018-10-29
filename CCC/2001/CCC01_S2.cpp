// https://dmoj.ca/problem/ccc02s2
// ---

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, d; cin >> n >> d;
	int front = n / d;
	int r = n % d;
	// check if fraction can be simplified
	int max = 0;
	for (int i = 2; i <= r; i++) {
		if (r % i == 0 && d % i == 0) {
			max = i;
		}
	}
	if (max > 0) {
		r /= max; d /= max;
	}
	if (r != 0) {
		if (front != 0) cout << front << " " << r << "/" << d << "\n";
		else cout << r << "/" << d << "\n";
	} else if (r == 0) {
		cout << front << "\n";
	}
}
