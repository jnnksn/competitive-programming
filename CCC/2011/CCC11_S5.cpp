// https://dmoj.ca/problem/ccc11s5
// 12/01/2018
/*
Similar to coin game and origin of life.
because of such small states, 25, we can represent this line in binary.
Thus, the maximum conversion between binary to decimal (1 << 25) is 2^25, which is 33,554,432.
on = 1, off = 0
So, each state of the current row represents a node in the graph, which we can BFS to. To determine the next
state, for each off light, we turn it on and see which "node" is adjacent. Then convert it to decimal. 
*/

#include <bits/stdc++.h>

#define MAXK (1 << 25)

using namespace std;

bitset<MAXK> vis;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/__RUN__/input.txt", "r", stdin);
#endif
	int K; cin >> K;
	bitset<25> state;
	for (int i = 0; i < K; i++) {
		int a; cin >> a;
		state[i] = a;
	}
	if (!state.to_ulong()) {
		cout << 0 << "\n";
		return 0;
	}
	int s_node = state.to_ulong();
	queue<int> q;
	q.push(s_node);
	int ans = 0;
	int prev = s_node;
	while (!q.empty()) {
		int n = q.front(); q.pop();
		state = (n);

		bitset<25> curr;
		int node;
		int last;
		for (int i = 0; i < K; i++) {
			if (state[i]) continue;

			curr = n;
			curr[i] = 1;
			node = curr.to_ulong();

			if (vis[node]) continue;
			vis[node] = 1;

			int total = 1;
			for (int x = i+1; x < K; x++) {
				if (curr[x]) total++;
				else break;
			}
			for (int x = i-1; x >= 0; x--) {
				if (curr[x]) total++;
				else break;
			}
			if (total >= 4) {
				for (int x = i; x < K; x++) {
					if (curr[x]) curr[x] = 0;
					else break;
				}
				for (int x = i-1; x >= 0; x--) {
					if (curr[x]) curr[x] = 0;
					else break;
				}
				node = curr.to_ulong();
			}
			if (curr.to_ulong() == 0) {
				cout << ans+1 << "\n";
				return 0;
			} else {
				q.push(node);
				last = node;
			}
		}
		if (n == prev) {
			ans++;
			prev = last;
		}
	}
}
