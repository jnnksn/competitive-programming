// https://dmoj.ca/problem/gfssoc1s5
// 08/14/2018
// -------------------------------------
// Issues I encountered:
// Instead of iterating through a vector to check if we can take a snowflake each time,
// just have 2d arrays to store the values, so you can quickly access / check.
// Also, I was using snowflakes despite that snowflake exceeding my backpack temp limit!
// -------------------------------------

#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 54;

int R, C, S, B, K, M;
int dp[MAX][MAX][MAX][MAX], val[MAX][MAX], temp[MAX][MAX];

int solve(int n, int t, int s, int p) {
	if (n == K || s > R) return 0;
	if (dp[n][t][s][p] != -1) return dp[n][t][s][p];

	int ans = 0;
	for (int i = 0; i <= M; ++i) {
		if (p+i <= C) {
			ans = max(ans, solve(n, t, s+1, p+i));
			if (val[s+1][p+i] > 0 && t+temp[s+1][p+i] < B) {
				ans = max(ans, solve(n+1, t+temp[s+1][p+i], s+1, p+i)+val[s+1][p+i]);
			}
		}
		if (p-i >= 1 && i != 0) {
			ans = max(ans, solve(n, t, s+1, p-i));
			if (val[s+1][p-i] > 0 && t+temp[s+1][p-i] < B) {
				ans = max(ans, solve(n+1, t+temp[s+1][p-i], s+1, p-i)+val[s+1][p-i]);
			}
		}
	}
	return dp[n][t][s][p] = ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));

	// Row, Col, # snow, < Max Temp, K snowflakes, M dist
	// Next #snow lines: Temp, Valu, c, r
	// R is snowflake height, C is psoition.
	cin >> R >> C >> S >> B >> K >> M;
	for (int i = 0; i < S; ++i) {
		int T, V, ci, ri; cin >> T >> V >> ci >> ri;
		val[ri][ci] = V; temp[ri][ci] = T;
	}

	cout << solve(0, 0, 0, 1) << "\n";
}
