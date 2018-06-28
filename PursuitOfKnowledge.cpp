// https://dmoj.ca/problem/gfssoc1j5
// 06/27/2018
// ---------------------------------
// BFS would probably be simpler, but 
// I used Dijkstra's since I'm
// learning it!
// ---------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1000;

vector<int> adj[MAXN+1];
int N, M, T, Q, a, b, S, E;
int dists[MAXN+1];
bool visited[MAXN+1];
priority_queue<pair<int, int>> q;

void solve() {
	fill(dists, dists+MAXN+1, 1e9);
	fill(visited, visited+MAXN+1, false);
	dists[S] = 0;
	q.push({0, S});
	while(!q.empty()) {
		int n = q.top().second; q.pop();
		if (visited[n]) continue;
		visited[n] = true;
		for (int u : adj[n]) {
			if (dists[n]+T < dists[u]) {
				dists[u] = dists[n]+T;
				q.push({-dists[u], u});
			}
		}
	}
}

int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	cin >> Q;

	for (int i = 0; i < Q; ++i) {
		cin >> S >> E;
		solve();
		if (dists[E] < 1e9) cout << dists[E] << "\n";
		else cout << "Not enough hallways!\n";
	}
}
