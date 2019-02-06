/*
https://dmoj.ca/problem/ccc05s3
02/05/2019

just implementation. 
*/
#include <bits/stdc++.h>

using namespace std;

//vector<vector<int>> matrix;
vector<vector<int>> tensor, nTensor;

int matrix[1040][1040];

int currR=1, currC=1;


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/WC/input.txt", "r", stdin);
#endif
	vector<int> x = {1};
	tensor.push_back(x);

	int N; cin >> N;

	int MAX = -1e9, MAXR = -1e9, MAXC = -1e9;
	int MIN = 1e9, MINR = 1e9, MINC = 1e9;

	for (int i = 0; i < N; i++) {
		int R, C; cin >> R >> C;
		nTensor.resize(R*currR);
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> matrix[r][c];
			}
		}

		for (int tr = 0; tr < currR; tr++) {
			for (int tc = 0; tc < currC; tc++) {
				int nRow = tr*R;
				for (int r = 0; r < R; r++) {
					for (int c = 0; c < C; c++) {
						int m = matrix[r][c] * tensor[tr][tc];
						nTensor[nRow].push_back(m);
					}
					nRow++;
				}
			}
		}

		tensor = nTensor;
		nTensor.clear();
		currR*=R; currC*=C;
	}

	for (int i = 0; i < currR; i++) {
		int sum = 0;
		for (int j = 0; j < currC; j++) {
			sum += tensor[i][j];
			MAX = max(MAX, tensor[i][j]);
			MIN = min(MIN, tensor[i][j]);
		}
		MAXR = max(MAXR, sum);
		MINR = min(MINR, sum);
	}

	for (int i = 0; i < currC; i++) {
		int sum = 0;
		for (int j = 0; j < currR; j++) {
			sum += tensor[j][i];
		}
		MAXC = max(MAXC, sum);
		MINC = min(MINC, sum);
	}
	cout << MAX << "\n" << MIN << "\n" << MAXR << "\n" << MINR << "\n" << MAXC << "\n" << MINC << "\n";
	return 0;
}
