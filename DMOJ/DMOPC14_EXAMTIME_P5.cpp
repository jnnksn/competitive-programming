// https://dmoj.ca/problem/dmopc14ce1p5
// 08/11/2018
// ---------------------------------------------
// I'm an idiot! I forgot to add a step...
// ---------------------------------------------

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct teacher {
	int v, d, t;
};

struct Ret {
	int v, t;
};

int N, MAX_T, vis[1004], MIN_S=1e9, res=-1;
Ret dp[54][1004];
vector<teacher> teach;

Ret solve(int t, int n) {
	if (n == -1 || t <= 0) {
		Ret tmp = {0, 0};
		return tmp;
	}
	
	if (dp[n][t].v != -1) return dp[n][t];
	
	
	int val = teach[n].v, d = teach[n].d, ti = teach[n].t;
	Ret ret = solve(t, n-1);
	int ans = ret.v;
	int mins = ret.t;
	int used = 1, temp_val=val;
	while (temp_val > 0 && (used*ti) <= t) {
		int tt = (used*ti);

		ret = solve(t-tt, n-1);

		if (ret.v+val > ans) {
			ans = ret.v+val;
			mins = ret.t+used;
		} else if (ret.v+val == ans) {
			mins = min(mins, ret.t+used);
		}

		used++;
		temp_val -= d;
		val += temp_val;
	}

	return dp[n][t] = {ans, mins};
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b, c; cin >> a >> b >> c;
		teach.push_back({a, b, c});
	}
	cin >> MAX_T;
	
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= 1002; ++j) {
			dp[i][j] = {-1, 0};
		}
	}
	
	Ret res = solve(MAX_T, N-1);
	cout << res.v << "\n" << res.t << "\n";
}
