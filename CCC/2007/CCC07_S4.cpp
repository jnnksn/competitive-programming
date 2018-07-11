// https://dmoj.ca/problem/ccc07s4
// 07/11/2018
// ----------------------------------------------------------------------------------------
// The Algorithm:
// This a graph theory AND dynamic programming
// We first notice that this is a directed graph, and acyclic, thus we can use a topological sort.
// Topological Sort: if there is a path from node a to node b, a will appear before b in ordering.
// The topologically sorted nodes are stored in an array, ts.
// 
// Once we discover our array, ts, we can continue with our dynamic programming.
// We let DP[x] represent the number of paths to node x.
// First, we set DP[1] = 1, since there is only 1 way to node 1.
// We then iterate through array ts, and it is essential that we iterate through nodes in topological order.
// We use our adjacency list, seeing which nodes are connected with the current node. 
// nodes that are connected with the current node will have the same number of paths with that node or greater.
// Thus, if a directed graph is 1 --> 2 --> 3
// we know that node 1 has only 1 path, and its adjacent node, 2, has ATLEAST 1 path as well. (In this case it is only 1 path,
// but I just wanted to emphasize my point).
// Thus the number of paths from the current node can be added to the number of paths to its adjacent nodes.
// this is will continue until we reach our last node in ts.
//
// We then output the value at DP[N].
// ----------------------------------------------------------------------------------------

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAXN = 10000;

stack<int> T;
vector<int> adj[MAXN+1], ts;
bool visited[MAXN+1];
int N, x, y, DP[MAXN+1];

void solve(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (auto u : adj[s]) solve(u);
	T.push(s);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	while (true) {
		cin >> x >> y;
		if (!x && !y) break;
		adj[x].push_back(y);
	}
	
	for (int i = N; i >= 1; --i) if (!visited[i]) solve(i);
	
	while (!T.empty()) {
		ts.push_back(T.top()); T.pop();
	}
	
	DP[1] = 1;
	
	for (int i = 0; i < N; ++i) {
		for (auto u : adj[ts[i]]) {
			DP[u] = DP[u] + DP[ts[i]];
		}
	}
	
	cout << DP[N] << "\n";

}
