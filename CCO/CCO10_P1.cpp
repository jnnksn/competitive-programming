// https://dmoj.ca/problem/cco10p1
// 07/18/2018
// -----------------------------------------
// At first I made a simple BFS, which produced
// correct outputs for the sample cases, but when put
// against actual test cases, it failed.
// This is where I had to make my own test cases! I would then put my own solution with
// that test case to see where I went wrong.
// I made a test case where we would have more than single connections
// between dogs (e.g. dog 1 barks to both dogs 2 and 3)
// Then included cases where a dog would bark to another dog that is waiting
// or barking. After these test cases, I noticed that I cannot use a queue,
// and that I had to evaluate all dogs at once every second, compared to
// evaluating by connections. 
// -----------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1000;

int w[MAX+1], STOP, inactive[MAX+1], ans[MAX+1];
vector<int> adj[MAX+1], times[MAX+1];

void solve() {
	times[0].push_back(1);
	for (int t = 0; t <= STOP; ++t) {
		for (int curr : times[t]) {
			ans[curr]++;
			for (int next : adj[curr]) {
				if (t + w[next] > STOP || inactive[next]) continue;
				times[t+w[next]].push_back(next);
				inactive[next] = true;
			}
		}
		for (int last : times[t]) inactive[last] = false;
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int d; cin >> d;
	for (int i = 1; i <= d; ++i) cin >> w[i];
	int f; cin >> f;
	for (int i = 1; i <= f; ++i) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
	cin >> STOP;
	solve();
	for (int i = 1; i <= d; ++i) {
		cout << ans[i] << "\n";
	}
}
