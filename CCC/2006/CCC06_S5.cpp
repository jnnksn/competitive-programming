// https://dmoj.ca/problem/ccc06s5
// 11/10/2018
// -------------------------------------------------------------
// Computer Engineering class saved me for this problem... 
// A good idea is to look at time constraints, since at first I thought my algorithm would be too slow...
//
// The Algorithm:
// This is similar to coin game, as we search for states of the board, and
// save states as integers by converting between decimal and binary (either alive or dead)
// Each state will represent a node, thus we can BFS to find the shortest distance to eden.
//
// At first I thought of determining the adjacency list by doing the opposite of the rules
// (e.g. convert from future state to past state), but it turns out that with the 10 second time limit,
// I can generate all possible paths for every possible state. Then, I can have a one way edge connecting a future state
// to a past state, without figuring out how to actually reverse the rules. Meaning, I generate my adjacency list by 
// converting past state --> future state. 
// Nodes will be stored through decimal by converting the boards into binary, then into decimal.
// The following is how they are stored:
// given a board where '1' represents alive and '0' represents dead:
// 1 0 1
// 1 1 1
// 1 0 0
// 
// This is equivalent to:
// 1 1 1 0 1 0 1 1 0
// Thus, for every section of length m in the binary, that represents a column.
// I use what I learned from comp eng to convert between binary and decimal.
//
// In order to determine the future state from the past state, we find the number of
// adjacent alive cells from every single cell and change their life according to the rules.
// 
// Once we have our adjacency list setup, we can simply bfs and note that edens are nodes in
// the adjacency list with no connections, since they don't originate from any other state.
// Then, take the eden with the least distance from the state that was given to us.
// -------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1050000;

vector<int> adj[MAX];
bool prevs[5][6], after[5][6];
int dist[MAX], vis[MAX];
int a, b, c, n, m;

int binary_to() {
	string seq = "";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			seq += (prevs[j][i] ? "1" : "0");
		}
	}
	reverse(seq.begin(), seq.end());
	int total=0;
	for (int i = 0; i < n*m; i++) {
		if (seq[i] == '0') continue;
		total += pow(2, i);
	}
	return total;
}

void to_binary(int state) {
	string seq = "";
	for (int i = 1; i <= (m*n); i++) {
		if (state%2==0) {
			seq += "0";
		} else {
			seq += "1";
		}
		state /= 2;
	}
	reverse(seq.begin(), seq.end());
	int index = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			prevs[j][i] = (seq[index] == '1' ? 1 : 0);
			index++;
		}
	}
}

int find_live(int i, int j) {
	int count = 0;
	if (i+1 <= m && prevs[i+1][j]) count++;
	if (i-1 >= 1 && prevs[i-1][j]) count++;
	if (j+1 <= n && prevs[i][j+1]) count++;
	if (j-1 >= 1 && prevs[i][j-1]) count++;
	if (j+1 <= n) {
		if (i+1 <= m && prevs[i+1][j+1]) count++;
		if (i-1 >= 1 && prevs[i-1][j+1]) count++;
	}
	if (j-1 >= 1) {
		if (i+1 <= m && prevs[i+1][j-1]) count++;
		if (i-1 >= 1 && prevs[i-1][j-1]) count++;
	}
	return count;
}

int next_state(int curr_state) {
	to_binary(curr_state);

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int adjacent = find_live(i, j);
			if (prevs[i][j] && (adjacent < a || adjacent  > b)) after[i][j] = 0;
			else if (!prevs[i][j] && adjacent > c) after[i][j] = 1;
			else after[i][j] = prevs[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			prevs[i][j] = after[i][j];
		}
	}
	return binary_to();
}

void solve(int src) {
	queue<int> q;
	dist[src] = 0;
	vis[src] = 1;
	q.push(src);
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		for (int u : adj[curr]) {
			if (vis[u]) continue;
			vis[u] = 1;
			dist[u] = dist[curr]+1;
			q.push(u);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/__RUN__/input.txt", "r", stdin);
#endif
	cin >> m >> n >> a >> b >> c;
	for (int i = 0; i <= (1<<(m*n)); i++) {
		int from = next_state(i);
		adj[from].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			char tmp; cin >> tmp;
			prevs[i][j] = (tmp == '.' ? 0 : 1);
		}
	}
	solve(binary_to());
	int ans = 1e6;
	for (int i = 0; i < (1<<(m*n)); i++) {
		if (adj[i].empty() && vis[i]) {
			ans = min(ans, dist[i]);
		}
	}
	cout << (ans == 1e6 ? -1 : ans) << "\n";
}
