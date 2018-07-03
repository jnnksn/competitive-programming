// https://dmoj.ca/problem/vmss7wc16c5p3
// 07/03/2018

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10000;

vector<int> adj[MAXN+1];
int dists[MAXN+1];
bool visited[MAXN+1];

int x, y, N, MAXD = -1, ans;

void solve(int s, int prev) {
	if (visited[s]) return;
	visited[s] = true;
	dists[s] = dists[prev] + 1;
	for (auto u : adj[s]) solve(u, s);
}

int main() {
	cin >> N;
	for (int i = 1; i < N; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int S = 1;

	for (int i = 0; i < 2; ++i) {
		fill(dists, dists+MAXN+1, -1);
		fill(visited, visited+MAXN+1, false);
		dists[S] = 0;
		solve(S, 0);
		for (int i = 1; i <= N; ++i) {
			if (dists[i] > MAXD) {
				ans = i;
				MAXD = dists[i];
			}
		}
		S = ans;
	}

	cout << MAXD << "\n";

}
