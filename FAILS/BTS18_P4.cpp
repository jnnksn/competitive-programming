#include <bits/stdc++.h>
using namespace std;

#define MAXN 100004

bool pho[MAXN], prune[MAXN], vis[MAXN];
int dist[MAXN], sz[MAXN], shift[MAXN];
vector<int> adj[MAXN];

void dfs(int n, int prev) {
	if (vis[n] || prune[n]) return;
	vis[n] = 1;
	dist[n] = dist[prev]+1;
	for (int nxt : adj[n]) {
		dfs(nxt, n);
	}
}
/*
int connect(int node) {
	int ret = 0;
	for (int nxt : adj[node]) {
		if (!prune[nxt]) {
			ret++;
			unprunned = nxt;
		}
	}
	return ret;
}
*/
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
						sz[path]--; break;
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
