#include <bits/stdc++.h>

using namespace std;

char graph[1004][1004];
bool vis[1004][1004];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int MAXA = 0, MINP = 1e9;

queue<pair<int, int>> q;

int count(int r, int c) {
	int cnt = 0;
	if (graph[r+1][c] != '#') cnt++;
	if (graph[r-1][c] != '#') cnt++;
	if (graph[r][c+1] != '#') cnt++;
	if (graph[r][c-1] != '#') cnt++;
	return cnt;
}

void fill(int r, int c) {
	vis[r][c] = 1;
	q.push({r, c});
	int per = count(r, c), area = 1;
	while (!q.empty()) {
		int ro = q.front().first, col = q.front().second;
		q.pop();
		for (auto d : dir) {
			int nr = ro+d.first, nc = col+d.second;
			if (vis[nr][nc] || graph[nr][nc] != '#') continue;
			vis[nr][nc] = 1;
			per += count(nr, nc);
			area++;
			q.push({nr, nc});
		}
	}
	if (area > MAXA) {
		MAXA = area;
		MINP = per;
	} else if (area == MAXA) {
		MINP = min(MINP, per);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifdef _DEBUG
		freopen("/Users/huogenx/Desktop/run/input.txt", "r", stdin);
	#else
	  freopen("perimeter.in", "r", stdin);
	  freopen("perimeter.out", "w", stdout);
	#endif
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!vis[i][j] && graph[i][j] == '#')
				fill(i, j);
		}
	}

	cout << MAXA << " " << MINP << "\n";
	return 0;
}
