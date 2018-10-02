// https://dmoj.ca/problem/ncco4d1p3
// 08/04/2018
// -------------------------------------------------------
// same as hungary games, however edges are undirected, thus we must try
// all possible paths using a certain edge forwards AND backwards.
// -------------------------------------------------------

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 5005;

int fdists[MAXN], bdists[MAXN];
priority_queue<pair<int, int>> q;
vector<pair<int, int>> adj[MAXN];
vector<pair<int, pair<int, int>>> edges;

void solve(int* dists, int src) {
	fill (dists, dists+MAXN, 1e9);
	dists[src] = 0;
	q.push({0, src});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		for (auto edge : adj[a]) {
			int b = edge.first, w = edge.second;
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
		int A, B, C; cin >> A >> B >> C;
		adj[A].push_back({B, C});
		adj[B].push_back({A, C});
		edges.push_back({C, {B, A}});
		edges.push_back({C, {A, B}});
	}

	solve(fdists, 1);
	solve(bdists, N);
	int shortest = fdists[N], ans = 1e9;
	for (auto e : edges) {
		int path = fdists[e.second.first] + bdists[e.second.second] + e.first;
		if (path > shortest && path < ans) ans = path;
	}
	cout << ans << "\n";
}
