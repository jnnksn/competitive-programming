#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 30000;

queue<int> q;
int adj[MAXN+1];
bool visited[MAXN+1];

int N, T, x;

void solve() {
	q.push(1);
	visited[1] = true;
	while(!q.empty()) {
		int a = q.front(); q.pop();
		if (!visited[a+adj[a]]) {
			visited[a+adj[a]] = true;
			q.push(a + adj[a]);
		}
	}
}

int main() {
	cin >> N >> T;
	for (int i = 1; i <= N-1; ++i) {
		cin >> adj[i];
	}
	
	solve();

	cout << (visited[T] ? "YES" : "NO") << "\n";

}
