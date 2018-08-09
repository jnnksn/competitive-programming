// https://dmoj.ca/problem/gfssoc2s4
// 08/09/2018
// --------------------------------------------------------------
// didn't take long at all as I've already encountered similar problems many times!
// one thing to keep note of are CORNER cases. Fortunately, they were given to me in the
// problem statement this time (which I ignored), and I was able to AC rather quickly afterwards.
// --------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 500005;

vector<pair<int, int>> fadj[MAXN], badj[MAXN];
vector<pair<int, pair<int, int>>> edges;
int fdists[MAXN], bdists[MAXN];
priority_queue<pair<int, int>> q;

void solve(int* dists, vector<pair<int, int>>* adj, int src) {
	fill(dists, dists+MAXN, 2e9);
	dists[src] = 0;
	q.push({0, src});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (dists[b] > dists[a]+w) {
				dists[b] = dists[a]+w;
				q.push({-dists[b], b});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b, c; cin >> a >> b >> c;
		fadj[a].push_back({b, c});
		badj[b].push_back({a, c});
	}
	int D; cin >> D;
	for (int i = 0; i < D; ++i) {
		int a, b, c; cin >> a >> b >> c;
		edges.push_back({c, {a, b}});
	}
	solve(fdists, fadj, 1);
	solve(bdists, badj, N);

	int ans = fdists[N];
	for (auto edge : edges) {
		int w = edge.first, a = edge.second.first, b = edge.second.second;
		ans = min(ans, fdists[a] + bdists[b] + w);
	}
	cout << (ans == 2e9 ? -1 : ans) << "\n";
}
