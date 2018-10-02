// https://dmoj.ca/problem/mwc15c4p4
// 07/03/2018
// ---------------------------------
// They specified that it was a one way connection...
// I assumed it was bi-directional.
// ---------------------------------

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;

vector<int> adj[MAXN+1];
bool visited[MAXN+1];
int N, X, Y, S, E;

void solve(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (auto u : adj[s]) solve(u);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> X >> Y;
		adj[X].push_back(Y);
	}

	cin >> S >> E;
	solve(S);
	cout << (visited[E] ? "Tangled" : "Not Tangled") << "\n";

}
