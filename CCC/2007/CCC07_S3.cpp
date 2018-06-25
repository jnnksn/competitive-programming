// https://dmoj.ca/problem/ccc07s3
// 06/25/2018
// -------------------------------
// Standard BFS
// For each query, you are given x, y
// where x is the start and y is the end.
// Using BFS, we can determine:
// visited --> friend circle
// distance --> seperation
// -------------------------------

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 9999;

int N, x, y, dists[MAXN + 1];
bool visited[MAXN + 1];
vector<int> adj[MAXN + 1];
queue<int> q;

void BFS() {
	visited[x] = true;
	q.push(x);
	while(!q.empty()) {
		int s = q.front(); q.pop();
		for (auto u : adj[s]) {
			if (visited[u]) continue;
			visited[u] = true;
			dists[u] = dists[s] + 1;
			q.push(u);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
	}

	while(true) {
		fill(visited, visited + MAXN + 1, false);
		fill(dists, dists + MAXN + 1, -1);
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		BFS();
		cout << (visited[y] ? "Yes" : "No");
		if (visited[y]) cout << " " << dists[y];
		cout << "\n";
	}

}
