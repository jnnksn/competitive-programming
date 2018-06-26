// https://dmoj.ca/problem/ddrp4
// 06/26/2018
// -----------------------------
// I got carried. At least I understand :/
// BTW what's with this indentation? WHAT THE HECK
// -----------------------------
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 500;

int dists[MAXN + 1][MAXN + 1], adj[MAXN + 1][MAXN + 1], N, Q, x, y;
string W[MAXN + 1];

void adjacent() {
	for (int i = 1; i < N; ++i) {
		for (int j = i+1; j <= N; ++j) {
			string s1 = W[i], s2 = W[j];
			int l1 = W[i].length(), l2 = W[j].length();
			bool valid = false;

			if (l2 > l1) {
				swap(l1, l2);
				swap(s1, s2);
			}
			
			if (l1 - l2 <= 1) {
				for (int z = 0; z < l2; ++z) {
					if (s1[z] != s2[z]) {
						if (l1 == l2) {
							valid = (s1.substr(z+1) == s2.substr(z+1));
						} else {
							valid = (s1.substr(z+1) == s2.substr(z));
						}
						break;
					}
				}

				if (s1.substr(0, l2) == s2) valid = true;

			}


			if (valid) {
				adj[i][j] = adj[j][i] = 1;
			} 
		}
	}
}

void FW() {
	for (int k = 1; k < N+1; ++k) {
		for (int i = 1; i < N+1; ++i) {
			for (int j = 1; j < N+1; ++j) {
				dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i < N + 1; ++i) cin >> W[i];

	adjacent();

	for (int i = 1; i < N+1; ++i) {
		for (int j = 1; j < N+1; ++j) {
			if (i == j) dists[i][j] = 0;
			else if (adj[i][j]) dists[i][j] = 1;
			else dists[i][j] = 1e9;
		}
	}

	FW();

	for (int i = 1; i < N+1; ++i) {
		for (int j = 1; j < N+1; ++j) {
			if (dists[i][j] == 1e9) dists[i][j] = -1;
		}
	}

	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> x >> y;
		cout << dists[x][y] << "\n";
	}

}
