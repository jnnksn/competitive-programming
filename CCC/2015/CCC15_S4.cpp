// https://dmoj.ca/problem/ccc15s4
// 06/29/2018

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 2000;

vector<pair<int, pair<int, int>>> adj[MAXN+1];
int dists[MAXN+1][201];
priority_queue<pair<int, pair<int, int>>> q;
bool visited[MAXN+1][201];
int K, N, M, a, b, t, h, S, E;

void solve() {
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			dists[i][j] = 1e9;
		}
	}

	dists[S][0] = 0;
	q.push({0, {0, S}});
	while(!q.empty()) {
		int a = q.top().second.second, z = q.top().second.first; q.pop();
		if (visited[a][z]) continue;
		visited[a][z] = true;
		for (auto u : adj[a]) {
			int x = u.first, w = u.second.first, d = u.second.second;
			for (int i = 0; i < K-d; ++i) {
				if (dists[a][i]+w < dists[x][i+d]) {
					dists[x][i+d] = dists[a][i] + w;
					q.push({-dists[x][i+d], {i+d, x}});
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> K >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> t >> h;
		adj[a].push_back({b, {t, h}});
		adj[b].push_back({a, {t, h}});
	}
	cin >> S >> E;
	solve();

	int ans = 1e9;

	for (int i = 0; i < K; ++i) ans = min(dists[E][i], ans);
	cout << (ans == 1e9 ? -1 : ans) << "\n";

}
