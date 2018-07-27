// https://dmoj.ca/problem/dmpg17b5
// 07/26/2018
// -----------------------------------
// Took lots of debugging, but turns out arrays
// are not filled with 0s by default...
// -----------------------------------

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int DP[1000007];
	fill(DP, DP+1000007, 0);
	for (int i = 1; i <= n; ++i) {
		int t, w; cin >> t >> w;
		for (int j = t; j <= 1000000; ++j) {
			if (DP[j] < w) DP[j] = w;
			else break;
		}
	}

	int q; cin >> q;
	for (int i = 1; i <= q; ++i) {
		int a; cin >> a;
		cout << DP[a] << "\n";
	}

}
