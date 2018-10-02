// https://dmoj.ca/problem/dwite09c2p4
// 07/02/2018

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 100;

vector<int> adj[MAXN];
int dists[MAXN];
bool visited[MAXN];
queue<int> q;
int N, X, Y, ans = -1;

void solve() {
	dists[1] = 0;
	visited[1] = true;
	q.push(1);

	while(!q.empty()) {
		int a = q.front(); q.pop();
		for (auto u : adj[a]) {
			if (visited[u]) continue;
			visited[u] = true;
			dists[u] = dists[a] + 1;
			//ans = max(ans, dists[u]);
			q.push(u);
		}
	}
}

int main() {
	for (int i = 0; i < 5; ++i) {
		ans = 0;
		fill(visited, visited+MAXN, false);
		fill(dists, dists+MAXN, 1e9);

		cin >> N;

		for (int j = 1; j <= N; ++j) adj[j].clear();

		for (int j = 0; j < N; ++j) {
			cin >> X >> Y;
			adj[X].push_back(Y);
		}

		solve();

		for (int j = 1; j <= N; ++j) {
			for (auto u : adj[j]) if (dists[u] == dists[j]) ans++;
		}

		cout << ans << "\n";

	}
}
