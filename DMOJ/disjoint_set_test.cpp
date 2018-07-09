// https://dmoj.ca/problem/ds2
// 07/09/2018

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int MAXN = 100000;

int N, M, u, v, link[MAXN+1], sizes[MAXN+1];
vector<pair<int, int>> graph;
vector<int> edge;

int find(int x) {
	while(x != link[x]) x = link[x];
	return x;
}

bool same(int a, int b) {
	return find(a) == find(b);
}

void unite(int a, int b) {
	a = find(a); b = find(b);
	if (sizes[a] < sizes[b]) swap(a, b);
	link[b] = a;
	sizes[a] += sizes[b];
}

int solve() {
	for (int i = 0; i < graph.size(); ++i) {
		int x, y; tie(x, y) = graph[i];
		if (!same(x, y)) {unite(x, y); edge.push_back(i+1);}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		cin >> u >> v; graph.push_back({u, v});
	}

	for (int i = 1; i <= N; ++i) {
		link[i] = i; sizes[i] = 1;
	}

	solve();

	if (edge.size() == N-1) for (int u : edge) cout << u << "\n";
	else cout << "Disconnected Graph\n";
}
