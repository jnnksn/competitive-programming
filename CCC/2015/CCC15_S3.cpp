// https://dmoj.ca/problem/ccc15s3
// 08/23/2018
// ------------------------------------------
// The Algorithm:
// This is a greedy algorithm, that is we always look for the highest numbered airport to be occupied.
// For each plane, we find the highest available spot possible. If one spot is taken, we go one down and check
// if that spot is taken as well. For each spot, we keep track of the number of times a plane "visits" it, that is
// the plane is considered for that spot. This allows us to quickly find the next available spot. For example:
// If 3 planes pass spot 4, then spots 4, 3, and 2 have already been taken, so we can go directly to spot 1. This
// will stop the Time Limit Exceeded!
// ------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int occupied[100004];
vector<int> occ;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int g; cin >> g;
	int p; cin >> p;
	for (int i = 0; i < p; ++i) {
		int t; cin >> t;
		occ.push_back(t);
	}
	int ans = 0;
	bool fail = false;
	for (int i = 0; i < p; ++i) {
		if (fail) break;
		int s = occ[i];
		while (true) {
			if (s <= 0) {
				fail = true;
				break;
			}
			if (occupied[s]) {
				int tmp = s;
				s -= occupied[tmp];
				occupied[tmp]++;
				continue;
			}
			occupied[s] = 1;
			ans++;
			break;
		}
	}
	cout << ans << "\n";
}
