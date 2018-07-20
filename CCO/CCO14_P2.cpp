// https://dmoj.ca/problem/cco14p2
// 07/20/2018
// ---------------------------------
// Just like "CCO Hungary Games"
// Dijkstras twice: time complexity --> 100,000 + 100,000 log 100,000
// My first mistake was using nested for loops with complexity: --> 100,000 * 100,000
// this clearly exceeds the 2 second limit. I ended up struggling to make a prefix sums array
// with a binary search. Had I known how to do a binary search properly, this would have been solved
// much faster. 
// ---------------------------------

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100000;

struct edge {
	int na, nb, w, cost;
};

vector<pair<int, int>> f_adj[MAX+1], b_adj[MAX+1];
vector<edge> edges;
bool f_vis[MAX+1], b_vis[MAX+1];
int f_dists[MAX+1], b_dists[MAX+1], sums[MAX+1];
int N, M, A, B;

void gen_dists_f() {
	priority_queue<pair<int, int>> q;
	f_dists[A] = 0;
	q.push({0, A});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (f_vis[a]) continue;
		f_vis[a] = true;
		for (auto u : f_adj[a]) {
			int w = u.first, b = u.second;
			if (f_dists[b] > f_dists[a]+w) {
				f_dists[b] = f_dists[a]+w;
				q.push({-f_dists[b], b});
			}
		}
	}
}

void gen_dists_b() {
	priority_queue<pair<int, int>> q;
	b_dists[B] = 0;
	q.push({0, B});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (b_vis[a]) continue;
		b_vis[a] = true;
		for (auto u : b_adj[a]) {
			int w = u.first, b = u.second;
			if (b_dists[b] > b_dists[a]+w) {
				b_dists[b] = b_dists[a]+w;
				q.push({-b_dists[b], b});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> A >> B;
	for (int i = 1; i <= M; ++i) {
		int X, Y, L, C; cin >> X >> Y >> L >> C;
		f_adj[X].push_back({L, Y});
		b_adj[Y].push_back({L, X});
		edges.push_back({X, Y, L, C});
	}
	for (int i = 1; i <= N; ++i) {
		f_dists[i] = 2000000000;
		b_dists[i] = 2000000000;
	}
	gen_dists_b();
	gen_dists_f();
	vector<pair<int, int>> ans;
	for (auto e : edges) ans.push_back({f_dists[e.na]+b_dists[e.nb]+e.w, e.cost});
	sort(ans.begin(), ans.end());

	for (int i = 1; i <= M; ++i) {
		sums[i] = sums[i-1] + ans[i-1].second;
	}

	int Q; cin >> Q;
	for (int i = 1; i <= Q; ++i) {
		int D; cin >> D;
		int s = 0, e = M-1;
		while (s <= e) {
			int k = (s+e)/2;
			if (ans[k].first > D) e = k-1;
			else s = k+1;
		}
		cout << sums[s] << "\n";
	}
}
