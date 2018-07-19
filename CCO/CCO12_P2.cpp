// https://dmoj.ca/problem/cco12p2
// 07/19/2018

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 20000;

vector<pair<int, int>> adj_f[MAXN+1], adj_b[MAXN+1];
vector<pair<int, pair<int, int>>> edges;
int f_dists[MAXN+1], b_dists[MAXN+1];
int N;

void gen_dists_f() {
	priority_queue<pair<int, int>> q;
	f_dists[1] = 0;
	q.push({0, 1});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		for (auto u : adj_f[a]) {
			if (f_dists[u.first] > f_dists[a]+u.second) {
				f_dists[u.first] = f_dists[a]+u.second;
				q.push({-f_dists[u.first], u.first});
			}
		}
	}
}

void gen_dists_b() {
	priority_queue<pair<int, int>> q;
	b_dists[N] = 0;
	q.push({0, N});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		for (auto u : adj_b[a]) {
			if (b_dists[u.first] > b_dists[a]+u.second) {
				b_dists[u.first] = b_dists[a]+u.second;
				q.push({-b_dists[u.first], u.first});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(f_dists, f_dists+MAXN+1, 2000000000);
	fill(b_dists, b_dists+MAXN+1, 2000000000);
	int m; cin >> N >> m;
	int A, B, L;
	for (int i = 0; i < m; ++i) {
		cin >> A >> B >> L;
		adj_b[B].push_back({A, L});
		adj_f[A].push_back({B, L});
		edges.push_back({L, {A, B}});
	}
	gen_dists_b();
	gen_dists_f();
	int spath = f_dists[N];
	int ans = 2000000000;
	for (auto edge : edges) {
		int d = f_dists[edge.second.first] + b_dists[edge.second.second] + edge.first;
		if (d > spath && d < ans) ans = d;
	}
	cout << (ans == 2000000000 ? -1 : ans) << "\n";
}
