// https://dmoj.ca/problem/dmopc15c3p3
// 07/03/2018
// ---------------------------
// We know that there is a cycle when we reach a node that has already been visited.
// ---------------------------


#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 20;

vector<int> adj[MAXN+1];
int dists[MAXN+1];
bool visited[MAXN+1];

int N, M, x, y;
bool ans = false;

void solve(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (auto u : adj[s]) {
	    int d = dists[s] - dists[u]+1;
		if (visited[u] && d >= 6) ans = true;
		dists[u] = dists[s] + 1;
		solve(u);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
	}

	fill(dists, dists+MAXN, 1e9);
	dists[1] = 0;

	solve(1);

	cout << (ans ? "YES" : "NO") << "\n";

}
