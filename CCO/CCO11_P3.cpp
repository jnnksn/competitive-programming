// https://dmoj.ca/problem/cco11p3
// 07/19/2018

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2000;

vector<int> adj[MAXN+1], visited[MAXN+1];
int cc[MAXN+1][MAXN+1];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	int k; cin >> k;
	for (int i = 1; i <= k; ++i) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}

	for (int i = 1; i <= n; ++i) {
		for (auto u : adj[i]) {
			if (visited[u].size() > 0) {
				for (auto z : visited[u]) {
					if (i < z) {
						cc[z][i]++;
					} else {
						cc[i][z]++;
					}
				}
			}
			visited[u].push_back(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (cc[i][j] > 1) {
				ans = 1; break;
			}
		}
	}
	cout << (ans == 1 ? "NO" : "YES") << "\n";
}
