// https://dmoj.ca/problem/vmss7wc16c3p2
// 07/02/2018

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2000;

vector<int> adj[MAXN+1];
bool visited[MAXN+1];
int N, M, A, B, X, Y;

void solve(int S) {
	if (visited[S]) return;
	visited[S] = true;
	for (auto u : adj[S]) {
		solve(u);
	}
}

int main() {
	cin >> N >> M >> A >> B;
	for (int i = 0; i < M; ++i) {
		cin >> X >> Y;
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}

	solve(A);

	cout << (visited[B] ? "GO SHAHIR!" : "NO SHAHIR!") << "\n";

}
