// https://dmoj.ca/problem/cco11p2
// 07/18/2018
 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1600;

vector<pair<int, pair<int, int>>> adj[MAXN+1];
int dists[MAXN+1][3601], S;
priority_queue<pair<int, pair<int, int>>> q;

void solve() {
	dists[0][0] = 0;
	// dist, next node, damage
	q.push({0, {0, 0}});
	while (!q.empty()) {
		int a = q.top().second.first, d = q.top().second.second; q.pop();
		for (auto u : adj[a]) {
			int b = u.second.first, w = u.first, above = u.second.second;
			if (above == 1 && dists[b][d+w] > dists[a][d]+w && d+w <= S) {
				dists[b][d+w] = dists[a][d]+w;
				q.push({-dists[b][d+w], {b, d+w}});
			} else if (above == 0 && dists[b][d] > dists[a][d]+w) {
				dists[b][d] = dists[a][d]+w;
				q.push({-dists[b][d], {b, d}});
			}
		}
	}
}

int main() {
	cin >> S;
	int N, E; cin >> N >> E;
	int x, y, d, k;
	for (int i = 1; i <= E; ++i) {
		cin >> x >> y >> d >> k;
		adj[x].push_back({d, {y, k}});
		adj[y].push_back({d, {x, k}});
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= S; ++j) {
			dists[i][j] = 1e9;
		}
	}

	solve();

	int ans = 1e9;
	for (int i = 0; i <= S; ++i) {
		ans = min(ans, dists[N-1][i]);
	}
	cout << (ans == 1e9 ? -1 : ans) << "\n";
}
