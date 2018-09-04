// https://dmoj.ca/problem/bts16p5
// 09/04/2018

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10004;

struct Ret {
	int weight, cherries;
};

vector<pair<int, int>> adj[MAXN];
int val[MAXN];
int N, C, K, ans=0;
bool vis[MAXN];

Ret solve(int node) {
	int cherries = val[node], weight = 0;
	for (auto u : adj[node]) {
		if (vis[u.first]) continue;
		vis[u.first] = 1;

		Ret v = solve(u.first);
		cherries += v.cherries;
		weight += v.weight + u.second;
		if (v.weight + u.second <= K && v.cherries >= C) ans++;
	}
	return {weight, cherries};
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> C >> K;
	for (int i = 1; i <= N; ++i) cin >> val[i];
	for (int i = 1; i < N; ++i) {
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	vis[1] = 1;
	solve(1);
	cout << ans << "\n";
}
