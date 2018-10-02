#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 54;

int world[MAX][MAX], N, M;
bool vol[MAX][MAX];
queue<pair<int, int>> q;

int solve(int a, int b) {
	int ret = 1;
	vol[a][b] = 1;
	q.push({a, b});
	bool failed = false;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		if (x == 1 || x == N || y == M || y == 1) failed = true;
				
		
		if (x+1 <= N && !vol[x+1][y]) {
			ret++;
			vol[x+1][y] = 1;
			q.push({x+1, y});
		}
		if (x-1 > 0 && !vol[x-1][y]) {
			ret++;
			vol[x-1][y] = 1;
			q.push({x-1, y});
		}
		if (y+1 <= M && !vol[x][y+1]) {
			ret++;
			vol[x][y+1] = 1;
			q.push({x, y+1});
		}
		if (y-1 > 0 && !vol[x][y-1]) {
			ret++;
			vol[x][y-1] = 1;
			q.push({x, y-1});
		}
	}

	if (!failed) return ret;
	else return 0;
}

int main() {
	int T = 5;
	while (T--) {
		int mh = -1, ans=0, ans1;
		cin >> N >> M;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				cin >> world[i][j];
				mh = max(mh, world[i][j]);
			}
		}
		for (int h = 1; h <= mh; ++h) {
			ans1 = 0;
			memset(vol, 0, sizeof(vol));
			for (int x = 1; x <= N; ++x) {
				for (int y = 1; y <= M; ++y) {
					if (world[x][y] >= h) {
						vol[x][y] = 1;
					}
				}
			}	
			
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= M; ++j) {
					if (!vol[i][j]) {
						ans1 = solve(i, j);
						ans+=ans1;
					}
					
				}
			}
		}
		cout << ans << "\n";
	}
}
