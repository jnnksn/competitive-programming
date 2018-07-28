// https://dmoj.ca/problem/coci07c6p4
// 07/28/2018
// ----------------------------------
// For some reason I never need to use a
// visited array for my dijkstra...
// ----------------------------------

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1005;

pair<int, pair<int, int>> adj[MAXN][MAXN];
int dists[MAXN], vis[MAXN], A, B, K, G, N, M;
priority_queue<pair<int, int>> q;

void solve() {
	fill(dists, dists+N+1, 1e9);
	dists[A] = K;
	vis[A] = 1;
	q.push({K, A});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		for (int i = 1; i <= N; ++i) {
			if (adj[a][i].first == -1) continue;
			//if (vis[i]) continue;
			//vis[i] = 1;
			int x = adj[a][i].second.first, y = adj[a][i].second.second;
			int w;

			if (dists[a] <= y && dists[a] >= x) {
				w = adj[a][i].first + (y - dists[a])+1;
			} else {
				w = adj[a][i].first;
			}

			cout << a << " " << i << " " << w << "\n";
			if (dists[i] > dists[a]+w) {
				dists[i] = dists[a]+w;
				q.push({-dists[i], i});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			adj[i][j] = {-1,{-1, -1}};
		}
	}
	// start, end, start time, george roads
	cin >> A >> B >> K >> G;
	int gv[MAXN];
	for (int i = 1; i <= G; ++i) cin >> gv[i];

	for (int i = 1; i <= M; ++i) {
		int x, y, l; cin >> x >> y >> l;
		adj[x][y] = {l, {0, 0}};
		adj[y][x] = {l, {0, 0}};
	}

	int s = 0;
	for (int i = 2; i <= G; ++i) {
		int w = adj[gv[i]][gv[i-1]].first;
		adj[gv[i]][gv[i-1]] = {w, {s, s+w-1}};
		adj[gv[i-1]][gv[i]] = {w, {s, s+w-1}};
		s += w;
	}

	solve();
	cout << dists[B] - K<< "\n";

}
