#include <bits/stdc++.h>

using namespace std;

struct turn {
	int a, b, g;
};

vector<turn> turns;

map<int, int> cup;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/run/input.txt", "r", stdin);
#else
  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);
#endif
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		turn x; cin >> x.a >> x.b >> x.g;
		turns.push_back(x);
	}
	int ans = 0;
	for (int i = 1; i <= 3; i++) {
		cup[1] = 0; cup[2] = 0; cup[3] = 0;
		cup[i] = 1;
		int cnt = 0;
		for (turn t : turns) {
			swap(cup[t.a], cup[t.b]);
			if (cup[t.g]) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
}
