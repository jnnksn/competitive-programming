#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1000004;

bool viable[MAXN], all_vis[MAXN], vis[MAXN];
int dists[MAXN];
vector<int> adj[MAXN];
int dia=0, node;

void solve(int n) {
	//if (i == 6) cout << n << "\n";
	all_vis[n] = 1;
	for (int no : adj[n]) {
		if (!viable[no] || vis[no]) continue;
        vis[no] = 1;
		dists[no] = dists[n]+1;
		if (dists[no] > dia) {
			dia = dists[no]; node = no;
		}
		solve(no);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;

	for (int i = 1; i <= N; ++i) {
		ll val; cin >> val;
		ll D = 1 + (4*val);

	    if (sqrt(D) == round(sqrt(D))) viable[i] = 1;

	}
	for (int i = 1; i < N; ++i) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		if (all_vis[i] || !viable[i]) continue;
		// reset
		memset(dists, 0, sizeof(dists));
		memset(vis, 0, sizeof(vis));
		// find first diam and node
		dia = -1; node = 1;
		vis[i] = 1;
		solve(i);

		// reset
		memset(vis, 0, sizeof(vis));
		memset(dists, 0, sizeof(dists));

		// find final diam
		dia = -1;
		vis[node] = 1;
		solve(node);
		ans = max(ans, dia);
	}
	cout << ans+1 << "\n";
}
