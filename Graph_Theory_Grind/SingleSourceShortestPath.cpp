// https://dmoj.ca/problem/sssp
// 07/03/2018

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1001;

int dists[MAXN];
bool visited[MAXN];
priority_queue<pair<int, int>> q;
vector<pair<int, int>> adj[MAXN];

int N, M, u, v, c;

void solve() {
	fill(dists, dists+MAXN, 1e9);
	dists[1] = 0;
	q.push({0, 1});
	while(!q.empty()) {
		int a = q.top().second; q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (dists[a] + w < dists[b]) {
				dists[b] = dists[a] + w;
				q.push({-dists[b], b});
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}

	solve();

	for (int i = 1; i <= N; ++i) {
		cout << (dists[i] == 1e9 ? -1 : dists[i]) << "\n";
	}

}
