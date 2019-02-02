#include <bits/stdc++.h>

using namespace std;

char arr[33][33];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/WC/input.txt", "r", stdin);
#endif
	int N; cin >> N;
	for (int i = 0; i < N-1; i++) {
		arr[0][i] = '#';
		arr[N-1][i] = '#';
	}
	for (int i = 1; i < N-1; i++) {
		arr[i][0] = '#';
		arr[i][N-1] = '#';
	}
	int x = 1;
	for (int i = N; i < N+N-1; i++) {
		arr[i][x] = '#';
		x++;
	}
	for (int i = N; i < N+N-1; i++) {
		arr[i][0] = '#';
	}
	for (int i = 0; i < N+N-1; i++) {
		for (int j = 0; j < N; j++) {
			cout << (arr[i][j]=='#'?'#':'.');
		}
		cout << "\n";
	}
	return 0;
}
