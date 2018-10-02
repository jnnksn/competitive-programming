#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int val[5], ro[5], rt[5], ans;

void solve(int c, int o, int w, int s, int depth) {
	ans = max(ans, o);
	if (depth == 3) return;
	if (c >= ro[1] && w >= ro[2]) {
		solve(c-ro[1], o+ro[4], w-ro[2], s+ro[3], depth+1);
	}
	if (s >= rt[1] && o >= rt[2]) {
		solve(c+rt[3], o-rt[2], w+rt[4], s-rt[1], depth+1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 10;
	while (T--) {
		cin >> val[1] >> val[2] >> val[3] >> val[4];
		cin >> ro[1] >> ro[2] >> ro[3] >> ro[4];
		cin >> rt[1] >> rt[2] >> rt[3] >> rt[4];
		ans = -1;
		solve(val[1], val[2], val[3], val[4], 0);
		cout << ans << "\n";
	}
}
