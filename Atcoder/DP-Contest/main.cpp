#include <bits/stdc++.h>
using namespace std;

#define MAXN 100004

struct Day {
    int a, b, c;
};

vector<Day> vacation;
int dp[MAXN][4];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
  freopen("/Users/huogenx/Desktop/__RUN__/input.txt", "r", stdin);
#endif
  int N; cin >> N;
  vacation.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> vacation[i].a >> vacation[i].b >> vacation[i].c;
  }
  for (int i = 1; i <= N; i++) {
    dp[i][1] = max(dp[i-1][2], max(dp[i-1][3], dp[i][1]));
    dp[i][1] += vacation[i-1].a;

    dp[i][2] = max(dp[i-1][1], max(dp[i-1][3], dp[i][2]));
    dp[i][2] += vacation[i-1].b;

    dp[i][3] = max(dp[i-1][2], max(dp[i-1][1], dp[i][3]));
    dp[i][3] += vacation[i-1].c;
  }
  cout << max(dp[N][1], max(dp[N][2], dp[N][3]));
}