// https://dmoj.ca/problem/cco14p1
// 08/01/2018
// --------------------------------
// working from bottom --> up, left --> right
// If a given square in the grid is a '#', then we perform the following:
// the value of the current square is equal to the minimum of the 3 squares below it
// (thus, down to the right, down, and down to the left) + 1
// and the sum of all the values in all squares is equal to the number of triangles!
// --------------------------------

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2004;
int dp[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char t; cin >> t;
			if (t == '#') dp[i][j] = 1;
		}
	}
	int ans = 0;
	for (int i = n; i >= 0; --i) {
		for (int j = 1; j <= n; ++j) {
			if (dp[i][j]) {
				dp[i][j] += min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]));
				ans += dp[i][j];
			}
		}
	}
	cout << ans << "\n";
}
