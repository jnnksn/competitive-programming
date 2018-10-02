// https://dmoj.ca/problem/graph1
// 07/03/2018
// -------------------------------
// I failed to notice the word "minimum" used
// in the problem.
// Originally I was outputting the distance, however
// it either takes 1 or 0 friends. If they are connected
// then it will always take only 1!
// -------------------------------

#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

const int MAXN = 10000;

vector<int> adj[MAXN+1];
bool visited[MAXN+1];
queue<int> q;

int N, M, X, Y, S, E;

void solve() {
	q.push(S);
	while(!q.empty()) {
		int a = q.front(); q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto u : adj[a]) q.push(u);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> X >> Y;
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}

	cin >> S >> E;

	solve();

	cout << (visited[E] ? 1 : 0) << "\n";

}
