// https://dmoj.ca/problem/dmopc13c3p5
// 08/11/2018

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dp[154][304][104], M, U, R;
vector<pair<int, pair<int, int>>> res;

int solve(int r, int t, int f) {
	if (r == -1 || t <= 0 || f <= 0) return 0;
	if (dp[r][t][f] != -1) return dp[r][t][f];
	int ans = -1;
	int val = res[r].first, ti = res[r].second.first, fo = res[r].second.second;

	int ans2 = solve(r-1, t, f), ans1 = -1;
	if (ti <= t && fo <= f) ans1 = val+solve(r-1, t-ti, f-fo);

	ans = max(ans, max(ans1, ans2));
	return dp[r][t][f] = ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> M >> U >> R;
	for (int i = 0; i < R; ++i) {
		int a, b, c; cin >> a >> b >> c;
		res.push_back({a, {b, c}});
	}
	memset(dp, -1, sizeof(dp));
	solve(R-1, M, U);
	cout << dp[R-1][M][U] << "\n";
}
