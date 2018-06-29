// https://dmoj.ca/problem/ccc15s4
// 06/29/2018

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

const int MAXN = 2000;

struct triple {
	int first, second, third;
	triple(int ff, int ss, int tt) {
		first = ff;
		second = ss;
		third = tt;
	}
};

vector<triple> adj[MAXN+1];
int dists[MAXN+1][201];
priority_queue<tuple<int, int, int>> q;
bool visited[MAXN+1][201];
int K, N, M, a, b, t, h, S, E;

void solve() {
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			dists[i][j] = 1e9;
		}
	}

	dists[S][0] = 0;
	q.push(make_tuple(0, 0, S));
	while(!q.empty()) {
		tuple<int, int, int> tmp = q.top();
		int a = get<2>(tmp), z = get<1>(tmp); q.pop();
		if (visited[a][z]) continue;
		visited[a][z] = true;
		for (auto u : adj[a]) {
			int x = u.first, w = u.second, d = u.third;
			for (int i = 0; i < K-d; ++i) {
				if (dists[a][i]+w < dists[x][i+d]) {
					dists[x][i+d] = dists[a][i] + w;
					q.push(make_tuple(-dists[x][i+d], i+d, x));
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> K >> N >> M;
	// a to b, takes t minutes, wears hull by h
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> t >> h;
		adj[a].push_back(triple(b, t, h));
		adj[b].push_back(triple(a, t, h));
	}
	cin >> S >> E;
	solve();

	int ans = 1e9;

	for (int i = 0; i < K; ++i) ans = min(dists[E][i], ans);
	cout << (ans == 1e9 ? -1 : ans) << "\n";

}
