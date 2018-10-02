// https://dmoj.ca/problem/cco10p4
// 08/01/2018

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 3005;
int dp[6][MAXN];
vector<pair<int, int>> parts[6];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int c, v, t; cin >> c >> v >> t;
		parts[t].push_back({c, v});
	}
	int b; cin >> b;
	for (int i = 1; i <= T; ++i) {
		for (int j = 0; j <= b; ++j) {
			dp[i][j] = dp[i-1][j]; // previous total cost
			for (auto p : parts[i]) {
				int c = p.first, v = p.second;
				// it either should remain the same as the previous
				// or if a previous cost + this cost's total value is greater,
				// then use it instead;
				if (c <= j) dp[i][j] = max(dp[i][j], dp[i-1][j-c] + v);
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= b; ++i) ans = max(ans, dp[T][i]);
	cout << ans << "\n";
}
