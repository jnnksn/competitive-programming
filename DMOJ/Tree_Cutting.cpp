// https://dmoj.ca/problem/tree2
// 08/08/2018

#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstring>
using namespace std;

int R, C, graph[11][11], e=-1, sX, sY;
priority_queue<pair<int, pair<int, int>>> q;
int dists[11][11], vis[11][11];

void solve() {
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			dists[i][j] = 1e9;
		}
	}
	dists[sY][sX] = 0;
	q.push({0, {sY, sX}});
	while (!q.empty()) {
		int y = q.top().second.first, x = q.top().second.second; q.pop();
		//cout << y << " " << x << "\n";
		if (x+1 <= C && dists[y][x]+graph[y][x+1] < dists[y][x+1]) {
			if (graph[y][x+1] > 0) vis[y][x+1] = vis[y][x]+1;
			else vis[y][x+1] = vis[y][x];
			dists[y][x+1] = dists[y][x]+graph[y][x+1];
			q.push({-graph[y][x+1], {y, x+1}});
		}
		if (x-1 > 0 && dists[y][x]+graph[y][x-1] < dists[y][x-1]) {
			if (graph[y][x-1] > 0) vis[y][x-1] = vis[y][x]+1;
			else vis[y][x-1] = vis[y][x];
			dists[y][x-1] = dists[y][x]+graph[y][x-1];
			q.push({-graph[y][x-1], {y, x-1}});
		}
		if (y+1 <= R && dists[y][x]+graph[y+1][x] < dists[y+1][x]) {
			if (graph[y+1][x] > 0) vis[y+1][x] = vis[y][x]+1;
			else vis[y+1][x] = vis[y][x];
			dists[y+1][x] = dists[y][x]+graph[y+1][x];
			q.push({-graph[y+1][x], {y+1, x}});
		}
		if (y-1 > 0 && dists[y][x]+graph[y-1][x] < dists[y-1][x]) {
			if (graph[y-1][x] > 0) vis[y-1][x] = vis[y][x]+1;
			else vis[y-1][x] = vis[y][x];
			dists[y-1][x] = dists[y][x]+graph[y-1][x];
			q.push({-graph[y-1][x], {y-1, x}});
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			char t; cin >> t;
			if (isdigit(t)) {
				graph[i][j] = t - '0';
				e = max(e, graph[i][j]);
			} else if (t == 'X') {
				graph[i][j] = 0;
				sX = j; sY = i;
			} else {
				graph[i][j] = 0;
			}
		}
	}

	int mdist = 1e9, mx, my;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			if (graph[i][j] < e) continue;
			int dist = sqrt(pow(sX - j, 2) + pow(sY - i, 2));
			if (dist < mdist) {
				mdist = dist;
				mx = j; my = i;
			}
		}
	}
	solve();
	
	cout << vis[my][mx] - 1 << "\n";
	
}
