// https://dmoj.ca/problem/ccc07s1
// 08/28/2018
// ---------------------------------------------
// I fail so hardz...
// I MESS UP IF STATEMENTS
// WHY...
// ---------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int y, m, d; cin >> y >> m >> d;
		if (y < 1989) cout << "Yes\n";
		else if (y == 1989 && m < 2) cout << "Yes\n";
		else if (y == 1989 && m == 2 && d <= 27) cout << "Yes\n";
		else cout << "No\n";
	}

}
