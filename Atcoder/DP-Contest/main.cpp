#include <bits/stdc++.h>
using namespace std;

#define MAXN 100004

int dp[MAXN];
int arr[MAXN];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
  freopen("/Users/huogenx/Desktop/__RUN__/input.txt", "r", stdin);
#endif
  int N, K; cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  fill(dp, dp+MAXN, 1e9);
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= K; j++) {
      dp[i+j] = min(dp[i+j], dp[i]+abs(arr[i]-arr[i+j]));
    }
  }
  cout << dp[N-1] << "\n";
}