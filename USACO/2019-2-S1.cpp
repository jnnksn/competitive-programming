#include <bits/stdc++.h>

using namespace std;

int deg[100004];


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifdef _DEBUG
		freopen("/Users/huogenx/Desktop/run/input.txt", "r", stdin);
	#else
	  freopen("planting.in", "r", stdin);
	  freopen("planting.out", "w", stdout);
	#endif
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 1; i < N; i++) {
		int a, b; cin >> a >> b;
		deg[a]++, deg[b]++;
		ans = max(ans, max(deg[a], deg[b]));
	}
	cout << ans + 1 << "\n";
	return 0;
}
