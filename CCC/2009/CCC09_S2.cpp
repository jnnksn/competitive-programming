// https://dmoj.ca/problem/ccc09s2
// 08/28/2018
// --------------------------------------------------------------
// The Algorithm:
// Each row depends on the row above it, therefore we start from second top row (top row depends on no row), and generate
// all "combinations" possible. So, we find all combinations on row K+1, then for the current row K, we compare it to all combinations
// of row K+1, then add the resulting row K to a vector of possible row K combinations. We can go downwards like this until we 
// reach row 1. The problem is that there will be repeats (since  both 0 0 and 1 1 --> 0, and both 1 0 and 0 1 --> 1)! Thus,
// once we find a possible combination, we check if it has been repeated yet, and depending on the feedback we will put it in the
// vector. 
// Given the small constraints, my essentially 4 nested for loops (including C++ inbuilt find function) works fine.
//
// Edit: Instead of iterating every time to check if a state is repeated, use C++ Set.
// --------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<string> rows[34];

int main() {
	int R, C; cin >> R >> C;
	for (int i = R; i >= 1; --i) {
		string tmp = "";
		for (int j = 1; j <= C; ++j) {
			int a; cin >> a;
			tmp += to_string(a);
		}
		rows[i].push_back(tmp);
	}
	for (int i = R-1; i >= 1; --i) {
		for (string curr : rows[i]) {
			for (string up : rows[i+1]) {
				string nstr = "";
				for (int x = 0; x < C; ++x) {
					if (curr[x] == up[x]) nstr += "0";
					else nstr += "1";
				}
				if (find(rows[i].begin(), rows[i].end(), nstr) != rows[i].end()) continue;
				else rows[i].push_back(nstr);
			}
		}
	}
	cout << rows[1].size() << "\n";
}
