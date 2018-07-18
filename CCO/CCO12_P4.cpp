// https://dmoj.ca/problem/cco12p4
// 07/18/2018
// -------------------------------
// Yes, it does look long, but copy and pasting is a thing!
// At first I read the problem incorrectly, and thought the limit
// was 100,000 by 100,000, which is a 2d array of 10 billion elements!
// Surprisingly, array sizes are limited to 4 billion elements.
// I was caught off guard on that one lol, then reread the problem where
// I realized it was 100,000 by 80...
// So yeah, rip.
// This type of problem seems to be used often...
// Similar problems are robothieves and maze. I actually think this problem should be 12 points on DMOJ
// since it is the same as the other two, but with many more cases. 
// -------------------------------

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAXN = 100000;

int dists[MAXN+1][81], num_col[MAXN+1];
int N;
queue<pair<int, int>> q;

void solve(int A, int B) {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= num_col[i]; ++j) {
			dists[i][j] = 2000000000;
		}
	}

	dists[A][B] = 0;
	q.push({A, B});
	while (!q.empty()) {
		int a, b; tie(a, b) = q.front(); q.pop();
		// UP CASE 1
		if (a - 1 > 0 && dists[a-1][b] > dists[a][b] + 1) {
			dists[a-1][b] = dists[a][b] + 1;
			q.push({a-1, b});
		}
		// UP CASE 2
		else if (a - 1 > 0 && b > num_col[a-1] && dists[a-1][num_col[a-1]] > dists[a][b] + 1) {
			dists[a-1][num_col[a-1]] = dists[a][b] + 1;
			q.push({a-1, num_col[a-1]});
		}
		// DOWN CASE 1
		if (a + 1 <= N && dists[a+1][b] > dists[a][b] + 1) {
			dists[a+1][b] = dists[a][b] + 1;
			q.push({a+1, b});
		}
		// DOWN CASE 2
		else if (a + 1 <= N && b > num_col[a+1] && dists[a+1][num_col[a+1]] > dists[a][b] + 1) {
			dists[a+1][num_col[a+1]] = dists[a][b] + 1;
			q.push({a+1, num_col[a+1]});
		}
		// LEFT CASE 1
		if (b - 1 > 0 && dists[a][b-1] > dists[a][b] + 1) {
			dists[a][b-1] = dists[a][b] + 1;
			q.push({a, b-1});
		}
		// LEFT CASE 2
		else if (b - 1 == 0 && a != 1 && dists[a-1][num_col[a-1]] > dists[a][b] + 1) {
			dists[a-1][num_col[a-1]] = dists[a][b] + 1;
			q.push({a-1, num_col[a-1]});

		}
		// RIGHT CASE 1
		if (b + 1 <= num_col[a] && dists[a][b+1] > dists[a][b] + 1 ) {
			dists[a][b+1] = dists[a][b] + 1;
			q.push({a, b+1});
		}
		// RIGHT CASE 2
		else if (b + 1 == num_col[a]+1 && a != N && dists[a+1][1] > dists[a][b] + 1) {
			dists[a+1][1] = dists[a][b] + 1;
			q.push({a+1, 1});
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> num_col[i];
	}
	int Ss, So, Es, Eo;
	cin >> Ss >> So >> Es >> Eo;
	solve (Ss, So);
	cout << dists[Es][Eo] << "\n";
}
