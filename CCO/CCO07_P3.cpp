// https://dmoj.ca/problem/cco07p3
// 08/13/2018
// --------------------------------------------
// .... I was actually so close to the correct solution!
// My own solution used the same idea, but for some reason I couldn't implement! :(
// I ended up giving up and using Andrew's solution. I think where I went wrong on my
// solution was on the prefix sum array. Anyways, I was really close which is good
// enough for me LOL!
// --------------------------------------------

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 10004, MAXK = 504;

int N, K, W, dp[MAXN+104][MAXK], arr[MAXN+104];

int solve(int n, int k) {
	if (n == 0 || k == 0) return 0;
	if (dp[n][k] != -1) return dp[n][k];

	int b = max(1, n - W + 1);
	int ba = arr[n] - arr[b-1];

	int ans = max(solve(n-1, k), solve(b-1, k-1) + ba);

	if (k < 2) return dp[n][k] = ans;

	for (int i = b; i >= max(1, b - W + 1); --i) {
		int sum = arr[b-1] - arr[i-1];
		ans = max(ans, solve(i-1, k-2)+sum+ba);
	}
	return dp[n][k] = ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	
  	while (T--) {
		memset(dp, -1, sizeof(dp));
		memset(arr, 0, sizeof(arr));
	  	cin >> N >> K >> W;
		for (int i = 1; i <= N; ++i) {
			cin >> arr[i];
			arr[i] += arr[i-1];
			
		}
		for (int i = N+1; i <= N+W; ++i) {
			arr[i] += arr[i-1];
		}
		cout << solve(N+W, K) << "\n";
  }
}
