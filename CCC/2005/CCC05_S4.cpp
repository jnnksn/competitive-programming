// https://dmoj.ca/problem/ccc05s4
// 06/27/2018
// -----------------------------------------------------
// I spent 20 minutes figuring out why I couldn't reset my vectors...
// I used vector.clear() at the end of each iteration, yet my program still wouldn't function properly
// I just ended up declearing my vectors at the start of each iteration, and that solved the problem.
// Still don't understand what went wrong... C++ is such a garbo language!
//
// The Algorithm:
// First we notice that the time it takes for the old method is 10 * (the number of times a node is visited)
// Thus 10 * (N).
//
// Then we notice that we only care about the longest path in the graph for the new method.
// since by the time the longest distance returns, all other graph paths have already returned, thus their time does not matter.
// We know that the time it takes to go from one name to another is 10, therefore it is 20 there and back.
// Thus, finding the distance from the root node to the farthest node, then multiplying that distance by 20 gives the time
// of the new method. The idea is --> (farthest node dist * 20) is the total time.
//
// We use BFS to determine the distances and keep a comparison variable to maintain the greatest distance.
// We notice that the last name given in the input will be the starting node since it will always return back to the root node.
// 
// The hardest part of the Algorithm is the creation of the adjacency list (this is where I somehow messed up resetting my
// vectors) 
// There are better methods, but here is mine:
// Have one vector keep track of distinct names, and let the index that has the name as its value represent the node number
// Then have another to keep track of the order of the nodes given.
// We then loop through the nodes in their given order, knowing that node[i-1] and node[i] are adjacent.
// Repeats don't matter since we have a visited array.
//
// Lastly, remember to reset all variables as the program deals with all testcases in one run. This is where I struggled...
// -----------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 100;


vector<int> adj[MAXN+1];
int N, L, dists[MAXN+1], S;
bool visited[MAXN+1];
queue<int> q;

int BFS() {
	fill(dists, dists+MAXN+1, 1e9);
	fill(visited, visited+MAXN+1, false);
	int ANS = -1;
	dists[S] = 0;
	visited[S] = true;
	q.push(S);

	while(!q.empty()) {
		int s = q.front(); q.pop();
		ANS = max(dists[s], ANS);
		for (auto u : adj[s]) {
			if (visited[u]) continue;
			visited[u] = true;
			dists[u] = dists[s] + 1;
			q.push(u);
		}
	}

	return ANS;

}

int main() {
	cin >> L;
	for (int _ = 0; _ < L; ++_) {
		string name;
		vector<string> names;
		vector<int> nodes;
		cin >> N;
		names.push_back("tmp");
		for (int i = 0; i < N; ++i) {
			cin >> name;
			bool valid = true;
			int it = names.size();
			for (int j = 1; j <= names.size(); ++j) {
				if (names[j] == name) {
					it = j;
					valid = false;
				}
			}
			if (valid) names.push_back(name);
			nodes.push_back(it);
		}

		for (int i = 0; i < N; ++i) {
			if (i == 0) continue;
			adj[nodes[i]].push_back(nodes[i-1]);
			adj[nodes[i-1]].push_back(nodes[i]);
			if (i == N-1) S = nodes[i];
		}
    
		cout << (N*10) - (BFS()*20) << "\n";
		for (int i = 1; i <= MAXN; ++i) adj[i].clear();

	}
}
