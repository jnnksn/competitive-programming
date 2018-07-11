// https://dmoj.ca/problem/vmss7wc15c4p3
// 07/11/2018

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 100000;

vector<pair<int, int>> adj[MAXN];
int N, M, A, B, t, dOne[MAXN], dTwo[MAXN];
bool visited[MAXN+1];
priority_queue<pair<int, int>> q;

void solOne() {
	fill(visited, visited+MAXN+1, false);
	dOne[0] = 0;
	q.push({0, 0});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (dOne[a]+w < dOne[b]) {
				dOne[b] = dOne[a]+w;
				q.push({-dOne[b], b});
			}
		}
	}
}

void solTwo() {
	fill(visited, visited+MAXN+1, false);
	dTwo[N-1] = 0;
	q.push({0, N-1});
	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (dTwo[a]+w < dTwo[b]) {
				dTwo[b] = dTwo[a]+w;
				q.push({-dTwo[b], b});
			}
		}
	}
}

int main() {
	fill(dOne, dOne+MAXN+1, 1e9);
	fill(dTwo, dTwo+MAXN+1, 1e9);
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		cin >> A >> B >> t;
		adj[A].push_back({B, t});
		adj[B].push_back({A, t});
	}

	solOne();
	solTwo();
	int ans = -1;
	for (int i = 0; i < N; ++i) {
		ans = max(ans , dOne[i] + dTwo[i]);
	}

	cout << ans << "\n";

}
