// https://dmoj.ca/problem/ccc12s3
// 08/24/2018
// -----------------------------------------------------------
// Comment:
// "If there are more than two readings that have the highest frequency..."
// It should be more than or equal to two!
// 
// The Algorithm:
// To be honest, I was playing league of legends while solving, and this solution is HORRIBLE,
// so I'm not going to explain this because it is just too stupid to do so.
// -----------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<int> readings;
vector<int> high, shigh;
set<int> each;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t; cin >> t;
		each.insert(t);
		readings.push_back(t);
	}
	int hi = -1, shi = -2;
	for (auto e : each) {
		int f = count(readings.begin(), readings.end(), e);
		if (f > hi) {
			if (hi > shi) {
				shigh.clear();
				shi = hi;
				for (int x : high) shigh.push_back(x);
			}
			high.clear();
			hi = f;
			high.push_back(e);
		} else if (f == hi) high.push_back(e);

		if (f < hi && f > shi) {
			shigh.clear();
			shi = f;
			shigh.push_back(e);
		} else if (f == shi) shigh.push_back(e);
	}

	if (high.size() >= 2) {
		int a = *max_element(high.begin(), high.end());
		int b = *min_element(high.begin(), high.end());
		cout << a - b << "\n";
	} else {
		int ans = 0;
		for (int e : shigh) {
			ans = max(ans, abs(high[0] - e));
		}
		cout << ans << "\n";
	}

}
