// https://dmoj.ca/problem/seed5
// 07/23/2018

#include <iostream>
#include <algorithm>
#include <queue>

#define IN(a) (2*(a)-1)
#define OUT(a) (2*(a))

using namespace std;

const int MAXN = 220;

bool visited[MAXN];
int adj[MAXN][MAXN], N, parent[MAXN];
queue<int> q;

bool dfs(int s) {
	visited[s] = true;
	if (s == IN(N)) return true;
	for (int u = 1; u <= IN(N); ++u) {
		if (visited[u]) continue;
		if (!adj[s][u]) continue;
		parent[u] = s;
		if (dfs(u)) return true;

	}
	return false;
}

bool bfs() {
	fill(visited, visited+MAXN, 0);
	q.push(IN(1));
	visited[IN(1)] = 1;
	parent[IN(1)] = -1;
	while (!q.empty()) {
		int a = q.front(); q.pop();
		for (int u = 1; u <= IN(N); ++u) {
			if (visited[u]) continue;
			if (!adj[a][u]) continue;
			parent[u] = a;
			visited[u] = true;
			q.push(u);
		}
	}

	return visited[IN(N)];
}

int solve() {
	int max_flow = 0;
	while (bfs()) {
		int mp = 2e9, p;
		for (int i = IN(N); i != 1; i = parent[i]) {
			p = parent[i];
			mp = min(mp, adj[p][i]);
		}
		for (int i = IN(N); i != 1; i = parent[i]) {
			p = parent[i];
			adj[p][i] -= mp;
			adj[i][p] += mp;
		}
		max_flow += mp;
	}
	return max_flow;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i) {
		cin >> adj[IN(i)][OUT(i)];
	}

	int M; cin >> M;

	for (int i = 1; i <= M; ++i) {
		int x, y; cin >> x >> y;
		adj[OUT(x)][IN(y)] = 2e9;
	}
	cout << solve() << "\n";
}
