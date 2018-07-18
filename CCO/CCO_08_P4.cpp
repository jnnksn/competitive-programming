// https://dmoj.ca/problem/cco08p4
// 07/17/2018
// -------------------------------
// I failed to realize that you cannot just
// count the number of cycles STARTING from an arbitrary node.
// Turns out you can reach node a from node b without being able to reach node b from node a.
// This results in additional and unneeded traps. We must keep track of places we have
// visited previously.
// -------------------------------

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

char grid[MAXN+1][MAXN+1];
bool vis;
int n, m, visited[MAXN+1][MAXN+1], t=1;
void solve(int a, int b) {
	if (visited[a][b]) {
		if (visited[a][b] == t) vis = true;
		else vis = false;
		return;
	}
	visited[a][b] = t;
	if (grid[a][b] == 'N') solve(a-1, b);
	else if (grid[a][b] == 'S') solve(a+1, b);
	else if (grid[a][b] == 'E') solve(a, b+1);
	else if (grid[a][b] == 'W') solve(a, b-1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> grid[i][j];
		}
	}
	int ans=0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (visited[i][j]) continue;
			vis = false;
			solve(i, j);
			if (vis) ans++;
			t++;
		}
	}
	cout << ans << "\n";
}
