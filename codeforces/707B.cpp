// http://codeforces.com/contest/707/problem/B
// 07/02/2018

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100000;
const int INF = 4e9;

vector<pair<pair<int, int>, int>> adj;
bool dests[MAXN+1];

int n, m, k, x, y, z;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		adj.push_back({{x, y}, z});

	}

	for (int i = 0; i < k; ++i) {
		cin >> x;
		dests[x] = true;
	}

	int ans = INF;

	for (auto u : adj) {
		int a = u.first.first, b = u.first.second, w = u.second;
		if (dests[a] && dests[b]) continue;
		if (!dests[a] && !dests[b]) continue;
		ans = min(ans, w);
	}

	cout << (ans==INF ? -1 : ans) << "\n";

}
