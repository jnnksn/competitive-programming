// https://dmoj.ca/problem/ccc03s5
// 07/02/2018
// --------------------------------
// The Algorithm:
// We need to find the maximum weight (MAXW) that can travel to all destinations, where the weight <= edge weights (w)
// thus, if MAXW > w then it cannot pass.
// 
// We can store all possible weights in a vector, then sort the vector from least to greatest.
// After, we can binary search the vector of weights.
// to determine whether the weight is too large or small, we can use Depth First Search
// It will be the standard DFS, but including a case where if MAXW > w it cannot move there.
// DFS will traverse through the graph, visiting all reachable nodes. 
// After using DFS, we iterate through all destination points, checking whether they were visited.
// if any of them was not visited, then it did not work, and this means that our MAXW was too large 
// (since any MAXW <= w will work)
// If it did work, we can try looking for a large value. 
// The above results in the maximum weight value.
// --------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 10000;

vector<pair<int, int>> adj[MAXN+1];
vector<int> dest, weights;
bool visited[MAXN+1];
queue<int> q;
int c, r, d, x, y, p, tmp, MAXW;

void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (auto u : adj[s]) {
		int b = u.first, w = u.second;
		if (MAXW > w) continue;
		dfs(b);
	}
}

int main() {
	cin >> c >> r >> d;
	for (int i = 0; i < r; ++i) {
		cin >> x >> y >> p;
		weights.push_back(p);
		adj[x].push_back({y, p});
		adj[y].push_back({x, p});
	}

	sort(weights.begin(), weights.end());

	for (int i = 0; i < d; ++i) {
		cin >> tmp;
		dest.push_back(tmp);
	}

	int a = 0, b = weights.size(), ans = -1;
	while (a < b) {
		fill(visited, visited+MAXN+1, false);
		int k = (a+b)/2;
		MAXW = weights[k];
		dfs(1);
		bool works = true;
		for (int i = 0; i < d; ++i) {
			if (!visited[dest[i]]) {
				works = false;
				break;
			}
		}

		if (!works) b = k-1;
		else {
			ans = MAXW;
			a = k + 1;
		}

	}

	cout << ans << "\n";

}
