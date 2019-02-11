/*
use long long instead of int. I CTRL-F'd to replace all int to long long.
Thus, there are some unneccesary long long usage.
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 10004;

ll sz[MAXN], dist[MAXN], vis[MAXN], par[MAXN], sum[MAXN];
vector<pair<ll, ll>> adj[MAXN];
priority_queue<pair<ll, ll>> q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifdef _DEBUG
		freopen("/Users/huogenx/Desktop/run/input.txt", "r", stdin);
	#else
	  freopen("shortcut.in", "r", stdin);
	  freopen("shortcut.out", "w", stdout);
	#endif
	ll N, M, T;
	cin >> N >> M >> T;
	for (ll i = 1; i <= N; i++) {
		cin >> sz[i];
	}
	for (ll i = 1; i <= M; i++) {
		ll a, b, t;
		cin >> a >> b >> t;
		adj[a].push_back({b, t});
		adj[b].push_back({a, t});
	}
	q.push({0, -1});
	fill(dist, dist+MAXN, 1e18);
	fill(par, par+MAXN, 1e18);
	dist[1] = 0;
	while (!q.empty()) {
		ll n = -q.top().second;
		q.pop();
		if (vis[n]) continue;
		vis[n] = 1;
		for (auto u : adj[n]) {
			ll b = u.first, w = u.second;
			if (dist[b] >= dist[n]+w) {
				if (dist[n]+w == dist[b]) par[b] = min(par[b], n);
				else par[b] = n;
				dist[b] = dist[n]+w;

				q.push({-dist[b], -b});
			}
		}
	}
	for (ll i = 1; i <= N; i++) {
		sum[i] += sz[i];
	 	for (ll j = i; j != 1; j = par[j]) {
			sum[par[j]] += sz[i];
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= N; i++) {
		ans = max(ans, (sum[i]*dist[i])-(T*sum[i]));
	}
	cout << ans << "\n";
	return 0;
}
