// https://dmoj.ca/problem/ccc12s4
// 08/20/2018
// -----------------------------------------------------------------------------------------------------------
// Comments:
// Overall, pretty easy... I would have solved faster if someone (*cough* *cough* Andrew Dong) didn't tell that
// storing states with strings + map would be too slow (HINT--> It's fast enough!)
// 
// The Algorithm:
// We will be using BFS to find our target state!
// Let each state, where state is the current position of the coins, represent a node in our graph.
// Thus, our starting node is the first state given to us, and our target node is the target state 
// (that is, coins arranged in numerical order).
// Two states (nodes) are adjacent if making (1) move and can reach, while keeping in mind that the move obeys the criteria:
// -> a coin can only be moved on top of a larger coin
// -> only a coin on top of the stack can be moved
// thus, at each state, we must find the coins on the top of each stack.
// Normally, BFS will have two arrays, one to check whether a node is visited, and another to store distances from the root node.
// A visited array will not be needed, since as long as we can reach the next state in less moves, we can use it!
//
// Now that we have covered how our BFS will function, we need to discuss how our states (nodes) are stored!
// If we think about a string, each string will have indices and values, where at each index a value can be found.
// Let the index of a string represent a coins value - 1 (e.g. index 1 represents coin 2), and the value at that index represent
// the position the coin is in. Obviously, we could use C++ map to access each state, but I did it differently so that each state
// in the vis array could be accessed in faster time. Therefore, I turned each string into an integer, so that it may be stored
// in an int array.
// To clarify, I will use the sample input of (3, 2, 1) to explain:
// our starting node is "321", where:
// coin 1 is in position 3
// coin 2 is in position 2
// coin 3 is in position 1
//
// let vis[321] = 0;
// Now let us move coin 1 to position 2! (3, 2, 1) --> (3, 1 2, _)
// the adjacent node to node "321" is "221", where
// coin 1 is in position 2
// coin 2 is in position 2
// coin 3 is in position 1
//
// This should be a rather simple BFS afterwards, and if the target node "123" is node visited, then it would be
// impossible!
// -----------------------------------------------------------------------------------------------------------

#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int N;
int vis[7777779];
queue<int> q;

bool check(string n) {
	for (int i = 1; i < N; ++i) {
		if (n[i] > n[i-1]) continue;
		return false;
	}
	return true;
}

int solve(int src) {
	int ans = -1;
	vis[src] = 0;
	q.push({src});
	while (!q.empty()) {
		string state = to_string(q.front()); q.pop();
		if (check(state)) {
			ans = vis[stoi(state)];
		}
		int top[N+1];
		fill (top, top+N+1, 20);
		for (int i = 1; i <= N; ++i) {
			top[state[i-1]-'0'] = min(top[state[i-1]-'0'], i); 
		}
	
		for (int i = 1; i <= N; ++i) {
			int a = state[i-1] - '0'; 
			if (top[a] != i) continue; 
			if (a + 1 <= N && i < top[a+1]) { 
				string tmp1 = state;
				tmp1[i-1] = (a+1) + '0';
				int t1 = stoi(tmp1);
				if (vis[stoi(state)] + 1 < vis[t1]) {
					vis[t1] = vis[stoi(state)] + 1;
					q.push(t1);
				}
			} 
			if (a - 1 > 0 && i < top[a-1]) {
				string tmp2 = state;
				tmp2[i-1] = (a-1) + '0';
				int t2 = stoi(tmp2);
				if (vis[stoi(state)] + 1 < vis[t2]) {
					vis[t2] = vis[stoi(state)] + 1;
					q.push(t2);
				}
				
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> N;
		if (N == 0) break;
		string base = "";
		for (int i = 1; i <= N; ++i) {
			base += "0";
		}
		
		for (int i = 1; i <= N; ++i) {
			int a; cin >> a;
			base[a-1] = i + '0';
		}
		int b = stoi(base);
		memset(vis, 80, sizeof(vis));
		int ans = solve(b);
		if (ans == -1) cout << "IMPOSSIBLE\n";
		else cout << ans << "\n";
	}
}
