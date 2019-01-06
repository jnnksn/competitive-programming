// https://dmoj.ca/problem/cco08p5
// 01/06/2019

#include <bits/stdc++.h>
using namespace std;

#define MAXV 5000004

struct Candy {
	int n, v;
};

int N, tot, sz;
vector<Candy> candy;
bool dp[MAXV];
int cnt[MAXV];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	candy.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> candy[i].n >> candy[i].v;
		tot += candy[i].n*candy[i].v;
	}
	dp[0] = 1;
	sz = tot / 2;
	for (int c = 0; c < N; c++) {
		for (int i = 0; i <= sz; i++) {
			cnt[i] = (dp[i] ? 0 : 1e6);
		}
		for (int j = 0; j <= sz; j++) {
			if (!dp[j] || cnt[j] >= candy[c].n || j+candy[c].v > sz) continue;
			dp[j+candy[c].v] = 1;
			cnt[j+candy[c].v] = min(cnt[j+candy[c].v], cnt[j]+1);
		}
	}
	int ans = 1e9;
	for (int i = 0; i <= sz; i++) {
		if (dp[i]) {
			ans = min(ans, tot - (2*i));
		}
	}
	cout << ans << "\n";
	
}
