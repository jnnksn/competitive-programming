// https://dmoj.ca/problem/ccc10s4
// 07/12/2018
// -------------------------------------------------------------------------------------------------------------
// My original solution was similar to Andrew Dong's (Same concept I believe), but failed a few test cases, so
// here is his... LOL
// 
// The Algorithm:
// Right away we should notice that this will be a minimum spanning tree problem, thus we can use Kruskals.
// The problem here is that we are given 2 options: Animals can meet inside OR outside! (LOL I fail)
// Thus, we must use kruskal's twice, once considering the minimum cost to move animals into a pen without using
// the outside edges, then the minimum cost to move animals into a pen (or outside) using outside edges and inside.
// BUT, this isn't enough! Finding the MST with the given graph won't give you your desired cost.
// We have to think differently about this...
// THE ANIMALS ARE IN THE PENS, NOT THE CORNERS! So, in the example graph given by the problem statement, they make it
// look like we should think of the corners as the nodes. But, we're moving animals from one pen to another, thus
// the pens themselves are nodes. Then fences that are adjacent to two pens are the edges between them.
// For example, if we examine the given sample graph:
//
// Let us label each pen numerically, read fron left to right, top to bottom (how you read things normally)
// 4, 1, 2, 3 (so the 5 fenced pen is 4, and bottom right pen is 3)
// The edge connecting pen 3 to pen 4 has weight of 4 (fence connected by corners 7 and 4) 
// Following the above idea:
// 2 3 --> 2 (4, 5)
// 1 2 --> 7 (1, 2)
// 1 4 --> 4 (2, 3)
// However, we must now remember that pens can connect to the outside! So the outside pen will be labelled 0
// Now, for example:
// ONE of the edges that connect pen 4 to outside 0 has weight 7 (fence connected by corners 7 and 8)
// We can then follow the above idea to produce:
// 1 0 --> 6 (3, 1)
// 2 0 --> 6 (1, 5)
// 4 0 --> 7 (3, 8) | This is the second edge that also has weight 7
// 3 0 --> 8 (7, 6)
// 3 0 --> 9 (6, 5)
//
// Now that we have found the actual graph, we can find the two MSTs (as stated previously), and the smallest of
// the two will be our minimum cost!
// One thing to keep in mind of is that edges only stated once lead to the outside. So, you will know
// which edges connect to node 0.
// the only difficult part of the input is that you must deal with cycles. When I observed others' solutions,
// they used modulus to restart a cycle. 
// I myself used 2 incrementing variables a and b, where a=0 and b=1. We increment after each iteration, and
// when one of the incrementing variables reach the number of corners, we reset it back to 0 (go back to start).
//
// What I covered above should be all the things you need to solve this problem, and I believe the rest
// is basic knowledge that one should already know before even attempting these type of problems.
// -------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 800;

vector<pair<int, pair<int, int>>> edge;
vector<int> node, weight, pens[MAXN+1][MAXN+1];
int N, y, e, link[MAXN+1], size[MAXN+1], W[MAXN+1][MAXN+1];

int find(int x) {
	while (x != link[x]) x = link[x];
	return x;
}

bool same(int a, int b) {
	return find(a) == find(b);
}

void unite(int a, int b) {
	a = find(a); b = find(b);
	if (size[a] < size[b]) swap(a, b);
	size[a] += size[b];
	link[b] = a;
}

void reset() {
	for (int i = 0; i <= MAXN; ++i) {
		link[i] = i; size[i] = 1;
	}
}

int solve() {
	int ansI=0, ansO=0;
	reset();
	for (int i = 0; i < edge.size(); ++i) {
		int a = edge[i].second.first, b = edge[i].second.second, w = edge[i].first;
		if (b == 0) continue;

		if (!same(a, b)) {
			unite(a, b); ansI += w;
		}

	}
	reset();

	for (int i = 0; i < edge.size(); ++i) {
		int a = edge[i].second.first, b = edge[i].second.second, w = edge[i].first;
		if (!same(a, b)) {
			unite(a, b); ansO += w;
		}
	}
	return min(ansI, ansO);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	// INPUT
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> e;
		for (int j = 1; j <= e; ++j) {
			cin >> y; node.push_back(y);
		}
		for (int j = 1; j <= e; ++j) {
			cin >> y; weight.push_back(y);
		}
		int a=0, b=1;
		for (int j = 0; j < e; ++j) {
			int ta = node[a], tb = node[b];
			if (ta < tb) swap(ta, tb);
			pens[ta][tb].push_back(i);
			W[ta][tb] = weight[j];
			a++; b++;
			if (b == e) b = 0;
			if (a == e) a = 0;
		}
		node.clear(); weight.clear();
	}

	for (int i = 1; i <= MAXN; ++i) {
		for (int j = 1; j <= MAXN; ++j) {
			if (pens[i][j].size() == 0) continue;
			if (pens[i][j].size() == 1) pens[i][j].push_back(0);
			edge.push_back({W[i][j], {pens[i][j][0], pens[i][j][1]}});
		}
	}

	sort(edge.begin(), edge.end());
	cout << solve() << "\n";
}
