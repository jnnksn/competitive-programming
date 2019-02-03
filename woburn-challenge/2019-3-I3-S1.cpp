#include <bits/stdc++.h>

using namespace std;

#define MAXN 300004

typedef long long ll;

vector<pair<int, int>> pkm;
bool vis[MAXN], take[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/WC/input.txt", "r", stdin);
#endif
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int T, L;
		cin >> T >> L;
		pkm.push_back({L, T});
	}
	sort(pkm.begin(), pkm.end());
	reverse(pkm.begin(), pkm.end());
	// round 1 --> Get a type for each.
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		if (vis[pkm[i].second]) continue;
		take[i] = 1;
		vis[pkm[i].second] = 1;
		ans += pkm[i].first;
	}
	M -= K;
	int ind = 0;
	while (M > 0) {
		ind++;
		if (take[ind]) continue;
		ans += pkm[ind].first;
		M--;
	}
	cout << ans << "\n";
	return 0;
}
