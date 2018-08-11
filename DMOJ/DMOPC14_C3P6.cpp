// https://dmoj.ca/problem/dmopc14c3p6
// 08/10/2018

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 2005;

int prep[MAX_SIZE][4], val[MAX_SIZE][4];
int dp[10005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, T; cin >> N >> T;
	for (int i = 1; i <= N; ++i) {
		int cc = 1;
		for (int j = 1; j <= 6; ++j) {
			if (j%2==0) {
				int p, v; cin >> p >> v;
				prep[i][cc] = p;
				val[i][cc] = v;
				cc++; 
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = T; j >= 0; --j) {
			for (int c = 1; c <= 3; ++c) {
				if (j - prep[i][c] >= 0) {
					dp[j] = max(dp[j], dp[j - prep[i][c]]+val[i][c]);
					ans = max(dp[j], ans);
				}
			}
		}
	}
	cout << ans << "\n";
}
