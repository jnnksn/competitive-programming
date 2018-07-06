// https://dmoj.ca/problem/ccc16s3
// 07/05/2018
// ----------------------------------
// The Algorithm:
// We are given a tree of restaurants along with the specifications of which are pho.
// Then, we are tasked with finding the minimum time to reach all pho restaurants. 
// 
// Firstly, even in the sample output explanation, they tell us to notice that some
// parts of the tree are not essential. Thus, we should remove unneeded nodes in order for later tasks.
// To remove nodes, we BFS from the leaves inward. Meaning, starting from a node with a degree of one, where
// the degree represents the number of nodes connected to that node, we BFS, keeping track of nodes that are
// unneeded, defined as those that are not pho restaurants. 
// Since we are only removing unwanted nodes starting from the leaves inwards, we won't remove needed nodes (pho or non-pho)
//
// After "prunning" our tree, we go find the diameter of the tree. To do so, we DFS starting at an arbitrary node, and determine
// the node with the greatest distance from our starting node. Then DFS from that furthest node and find the greatest distance
// from that node. This distance will be our tree's diameter.
//
// Our answer will be: 2 * (num_nodes - 1) - diameter
// why?
// To visit all leaves and return back to the starting node, we visit all edges twice. Thus, the time taken is calculated as
// 2 * (num_nodes - 1). However, in the problem we don't need to return to our starting position! The number of additional
// steps we took is equal to the diameter!
// for example, in our sample input:
//      6              4
//      |              |
// 5 -- 1 -- 0 -- 2 -- 3 -- 7   <-- REMEMBER WE REMOVED 5 WHEN WE WERE PRUNNING THE TREE
//
// If we started at 5, and visited all leaves, then returned back to 6, it would take 2 * (7-1) = 12 minutes.
// That is, visit each edge TWICE.
// By returning back to 6, we are increasing the time needed by 5 minutes (total 12).
// Guess what? The diameter of our tree is 5! So, if we didn't go back, our minimum time would be 12 - 5 = 7 minutes!
// WOAH AMAZING! WOW! Congratulations, you now know what to do! Have fun implementing.
// ----------------------------------

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 100001;

int N, M, t, y, diameter, S;

bool pho[MAXN], removed[MAXN], visited[MAXN];
int degree[MAXN], dists[MAXN];
vector<int> adj[MAXN];
queue<int> q;

void tree_prunning() {
	while (!q.empty()) {
		int a = q.front(); q.pop();
		removed[a] = true;
		for (auto u : adj[a]) {
			if (pho[u] || visited[u] || degree[u] != 1) continue;
			visited[a] = true;
			for (auto j : adj[u]) degree[j]--;
			degree[u]--;
			q.push(u);
		}
	}
}

void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (auto u : adj[s]) {
		if (removed[u] || visited[u]) continue;
		dists[u] = dists[s] + 1;
		if (dists[u] > diameter) {
			diameter = dists[u]; S = u;
		}
		dfs(u);
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> S; pho[S] = true;
	}

	for (int i = 1; i < N; ++i) {
		cin >> t >> y;
		adj[t].push_back(y); adj[y].push_back(t);
		degree[t]++; degree[y]++;
	}

	for (int i = 0; i < N; ++i) {
		if (degree[i] == 1 && !pho[i]) {
			for (auto u : adj[i]) degree[u]--;
			degree[i]--;
			visited[i] = true;
			q.push(i);
		}
	}

	tree_prunning();

	for (int i = 0; i < 2; ++i) {
		fill (visited, visited+MAXN, false);
		fill (dists, dists+MAXN, 0);
		diameter = -1;
		dfs(S);
	}

	int n_nodes = 0;
	for (int i = 0; i < N; ++i) if (!removed[i]) n_nodes++;
	cout << 2 * (n_nodes-1) - diameter << "\n";
}
