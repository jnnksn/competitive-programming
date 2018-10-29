// https://dmoj.ca/problem/ccc02s3
// October

#include <bits/stdc++.h>
using namespace std;

struct spot {
	int r, c;
};

char grid[380][85];
vector<char> dir;

int R, C, T;

void move(spot S, char face) {
	int count = 0;
	for (int i = 0; i < T; i++) {
		if (dir[i] == 'F') {
			if (face == 'U') {
				if (S.r-1 >= 1 && grid[S.r-1][S.c] != 'X') {
					S.r--;
				} else break;
			} else if (face == 'D') {
				if (S.r+1 <= R && grid[S.r+1][S.c] != 'X') {
					S.r++;
				} else break;
			} else if (face == 'L') {
				if (S.c-1 >= 1 && grid[S.r][S.c-1] != 'X') {
					S.c--;
				} else break;
			} else if (face == 'R') {
				if (S.c+1 <= C && grid[S.r][S.c+1] != 'X') {
					S.c++;
				} else break;
			}
		} else if (dir[i] == 'L') {
			if (face == 'R') face = 'U';
			else if (face == 'L') face = 'D';
			else if (face == 'U') face = 'L';
			else face = 'R';
		} else {
			if (face == 'R') face = 'D';
			else if (face == 'L') face = 'U';
			else if (face == 'U') face = 'R';
			else face = 'L';
		}
		count++;
	}
	if (count == T) {
		grid[S.r][S.c] = '*';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> grid[i][j];
		}
	}
	cin >> T;
	dir.resize(T);
	for (int i = 0; i < T; i++) {
		cin >> dir[i];
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (grid[i][j] == 'X') continue;
			spot curr = {i, j};
			move(curr, 'U');
			move(curr, 'D');
			move(curr, 'L');
			move(curr, 'R');
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << grid[i][j];
		}
		cout << "\n";
	}
}
