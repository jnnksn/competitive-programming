// https://dmoj.ca/problem/ccc15s4
// 06/29/2018
// -----------------------------------------------------------------------
// The Algorithm:
// We first notice that we must find the shortest path from island A to B, with no negative weights (time > 0)
// Thus, we are able to use Dijkstra's Algorithm to solve this problem.
// This would be a direct implementation of Dijkstra, but the problem throws in another variable --> hull damage
// The only impact this variable has is that we will be using a 2D distance array.
// Since, we are no longer keeping track of just the distance from node X to Y, but
// the distance from node X with hull damage i to node Y with hull damage i+h (where h is how much the hull is damaged
// going from X to Y).
// Therefore, we can use dists[i][j], where i represents the node and j the amount of damage that has been taken.
// For example:
// Going from island 5 to island 6, we take 5 damage to our hull, and it takes 10 minutes.
// The distance can be represented as: dists[6][i+5] = dists[5][i] + 10, where i is the previous amount of damage at island 5. 
// So, as long as i+h < K, it is possible.
//
// Another alteration is that we will not need a visited array, since each [node][dmg] will only be visited once!
//
// Finally, loop through dists[E][i], where E is the end node and i is the damage taken from 0 to K-1, keeping track
// of the smallest distance.
// -----------------------------------------------------------------------

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 2000;

vector<pair<int, pair<int, int>>> adj[MAXN+1];
int dists[MAXN+1][201];
priority_queue<pair<int, pair<int, int>>> q;
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
		for (auto u : adj[a]) {
			int x = u.first, w = u.second.first, d = u.second.second;
			if (z+d < K && dists[a][z]+w < dists[x][z+d]) {
				dists[x][z+d] = dists[a][z] + w;
				q.push({-dists[x][z+d], {z+d, x}});
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
