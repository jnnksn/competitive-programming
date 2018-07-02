// http://codeforces.com/contest/520/problem/B
// 07/02/2018
// -------------------------------------------
// Set a hard limit for 2*a, which should
// be maximum M (10000)
// -------------------------------------------
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 10000;

int dists[MAXN+1];
int n, m;
queue<int> q;

void solve() {
	fill(dists, dists+MAXN+1, 1e9);
	dists[n] = 0;
	q.push(n);

	while(!q.empty()) {
		int a = q.front(); q.pop();

		if (2*a > 0 && dists[a] + 1 < dists[2*a] && 2*a <= MAXN) {
			dists[2*a] = dists[a] + 1;
			q.push(2*a);
		}

		if(a-1 > 0 && dists[a] + 1 < dists[a-1]) {
			dists[a-1] = dists[a] + 1;
			q.push(a-1);
		}

	}

}

int main() {
	cin >> n >> m;
	solve();
	cout << dists[m] << "\n";
}
