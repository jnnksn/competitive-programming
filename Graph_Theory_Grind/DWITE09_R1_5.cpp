// https://dmoj.ca/problem/dwite09c1p5
// 07/02/2018
// -----------------------------------
// Don't assume that cycle will start
// and end on 1.
// Also don't assume graph will traverse in numeric order.
// -----------------------------------

#include <iostream>
#include <vector>
using namespace std;

int dists[101];
vector<int> adj[101];
bool visited[101];

int N, X, Y, ans;

void solve(int s, int prev) {
	dists[s] = dists[prev]+1;
	visited[s] = true;
	for (auto u : adj[s]) {
		if (visited[u]) {
			ans = max(ans, dists[s] - dists[u]+1);
			return;
		}
		solve(u, s);
	}
}

int main() {
	for (int _ = 0; _ < 5; ++_) {
		ans = 1;
		fill(visited, visited+101, false);
		cin >> N;
		for (int i = 1; i <= N; ++i) adj[i].clear();

		for (int i = 0; i < N; ++i) {
			cin >> X >> Y;
			adj[X].push_back(Y);
		}

		solve(1, 0);
		cout << ans << "\n";
	}
}
