#include <bits/stdc++.h>

using namespace std;

priority_queue<int> q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/WC/input.txt", "r", stdin);
#endif
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		q.push(a);
	}
	int ans = 0;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.top(); q.pop();
		if (x > 100 || cnt == 2) continue;
		ans += x;
		cnt++;
	}
	cout << ans << "\n";
	return 0;
}
