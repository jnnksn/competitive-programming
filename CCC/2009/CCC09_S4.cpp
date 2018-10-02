// https://dmoj.ca/problem/ccc09s4
// 06/26/2018
// -------------------------------
// Note to self: Remember to grab all inputs! I spent 10 minutes figuring out what was wrong,
// then realized I didn't even take D as an input yet...
//
// The Algorithm:
// We must go from a city with a pencil to the destination
// We could have multiple starting points that go to D, or
// Go from D and use Dijkstras.
//
// This is literally pure Dijkstras, just starting from D.
// The distances represent the cost.
//
// To find the lowest cost:
// Loop through all nodes with pencils
// Compare the distances of each node from D + the initial cost of their pencil
// the lowest one is the answer.
// -------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 5000;

vector<pair<int, int>> adj[MAXN+1];
int N, T, x, y, c, K, D;
int dists[MAXN+1];
vector<pair<int, int>> pencils;
priority_queue<pair<int, int>> q;
bool visited[MAXN+1];

void dijkstras() {
	fill(dists, dists+MAXN+1, 1e9);
	fill(visited, visited+MAXN+1, false);
	dists[D] = 0;
	q.push({0, D});
	while(!q.empty()) {
		int a = q.top().second; q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (dists[a]+w < dists[b]) {
				dists[b] = dists[a] + w;
				q.push({-dists[b], b});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> T;
	for (int i = 0; i < T; ++i) {
		cin >> x >> y >> c;
		adj[x].push_back({y, c});
		adj[y].push_back({x, c});
	}
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> x >> y;
		pencils.push_back({x, y});
	}
	cin >> D;

	dijkstras();

	int ans = 1e9;
	for (int i = 0; i <= pencils.size(); ++i) {
		ans = min(dists[pencils[i].first] + pencils[i].second, ans);
	}

	cout << ans << "\n";
}
