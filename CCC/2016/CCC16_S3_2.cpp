// https://dmoj.ca/problem/ccc16s3
// 12/31/2018
/*
It's new years eve at 11:17PM. It has almost been 6 months since I last solved this problem,
and I have completely forgotten how to do it! Below is the implementation that I thought of.
It is very similar to the first one! So, maybe I didn't completely forget. Seems that I trimmed differently, though.
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100004

bool pho[MAXN], prune[MAXN], vis[MAXN];
int dist[MAXN], sz[MAXN];
vector<int> adj[MAXN];

void dfs(int n, int prev) {
	if (vis[n] || prune[n]) return;
	vis[n] = 1;
	dist[n] = dist[prev]+1;
	for (int nxt : adj[n]) {
		dfs(nxt, n);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/__RUN__/input.txt", "r", stdin);
#endif

	int N, M; cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int res; cin >> res;
		pho[res] = 1;
	}
	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		sz[a]++; sz[b]++;
	}
	for (int i = 0; i < N; i++) {
		if (adj[i].size() == 1 && !pho[i]) {
			prune[i] = 1;
			int path = adj[i][0];
			sz[adj[i][0]]--;
			while (!pho[path] && sz[path] == 1) {
				prune[path] = 1;
				for (int nxt : adj[path]) {
					if (!prune[nxt]) {
						path = nxt;
						sz[path]--;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (!prune[i]) {
			dfs(i, MAXN-1);
		}
	}
	int d, len=0;
	for (int i = 0; i < N; i++) {
		if (dist[i] > len) {
			len = dist[i];
			d = i;
		}
	}
	fill(dist, dist+MAXN, 0);
	fill(vis, vis+MAXN, 0);
	dfs(d, MAXN-1);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dist[i]);
	}
	int valid = 0;
	for (int i = 0; i < N; i++) {
		//cout << prune[i] << "\n";
		if (!prune[i]) {
			valid++;
		}
	}
	cout << (2 * valid - 1) - ans << "\n";
}
