// https://dmoj.ca/problem/hci16police
// 08/26/2018

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100004;
typedef long long ll;

int N, H;
ll dp[MAXN];
vector<int> road;

ll solve(int n) {
	if (n == -1) return 0;
	if (dp[n] != -1) return dp[n];
	ll ans = solve(n-1) + H;
	for (int i = n-1; i >= 0; --i) {
		ll a = pow(road[n] - road[i], 2);
		if (a > 206116) break;
		ans = min(ans, H+a+solve(i-1));
	}
	return dp[n] = ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> H;
	for (int i = 1; i <= N; ++i) {
		int t; cin >> t;
		road.push_back(t);
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(N-1) << "\n";

}
