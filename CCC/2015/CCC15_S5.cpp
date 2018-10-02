// https://dmoj.ca/problem/ccc15s5
// 08/30/2018
// --------------------------------------------
// Note:
// Thanks to Wesley-A-Leung... 
// Our solutions were pretty similar, but I'll admit that his was
// written in MUCH less lines than mine, so I give a slightly trimmed version of mine, and below it is my version of his.
//
// The Algorithm:
// We ask ourselves this, "What are the purposes for inserting pies?"
// 1. To go inbetween two pies already in the line
// 2. To use one of the inserted pies for its sugar content
// It is reasonable to claim that we will always want to take inserted pies with the most
// sugar content, and always use the ones with the least sugar content as dividers.
//
// Our DP states are:
// 1. index of current pie in main line
// 2. index of lowest sugar insertable pie
// 3. index of highest sugar insertable pie
// 4. whether the pie to the left of the current pie was taken
//
// Then, to generate the most amount of pies we go through the following cases:
// 1. SKIP current pie
// 2. if last taken, add divider pie
// 3. if last not taken, take current pie
// 4. if last not taken, insert big pie to left to be taken
// 
// We then consider when we put pies on the right and left ends of the main line:
// --> No point in adding pies to both LEFT and RIGHT ends, so choose one end (in this case, the right)
// --> With leftover pies, we do our best to GET THE MOST SUGAR, to do this we obey the following pattern:
//     if last taken: Insert divider
//     else: Take the largest insertable pie
//     We obey until all insertable pies are exhausted.
// --> About the first point... I'm not too sure? At first, I thought that the optimal end to start in was the end where
//     its adjacent pie was not taken, so we could right away start taking pies. However, after seeing wleung's solution,
//     it does not seem that this is true. The code displayed is the one accounting for the front, however, it is
//     unneeded as you can AC without accounting for it.
//
// Remember case where M = 0, since if you start your arrays at index 0, it may mess up the values.
// You could account for when M = 0 in many ways, one way could be to start arrays at 1.
// --------------------------------------------

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3004;

vector<int> curr, insert;
int N, M;
ll dp[MAXN][104][104][2];

ll solve(int n, int s, int e, bool l, int front) {
	if (dp[n][s][e][l] != -1) return dp[n][s][e][l];
	ll ans;
	if (n == N) {
		if (s <= e) {
			if (l) ans = solve(n, s+1, e, 0, front);
			else if (front == 0) ans = solve(n, s, e-1, 1, front-1) + insert[e];
			else ans = solve(n, s, e-1, 1, front) + insert[e];
		} else {
			ans = 0;
		}
		return dp[n][s][e][l] = ans;
	}

	if (l) {
		ans = solve(n+1, s, e, 0, front);
		if (s <= e) ans = max(ans, solve(n, s+1, e, 0, front));
	} else {

		if (n > 0) ans = solve(n+1, s, e, 1, front) + curr[n];
		else ans = solve(n+1, s, e, 1, 1) + curr[n];
		ans = max(ans, solve(n+1, s, e, 0, front));
		if (e >= s) ans = max(ans, solve(n, s, e-1, 1, front)+insert[e]);
	}
	return dp[n][s][e][l] = ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp; cin >> tmp;
		curr.push_back(tmp);
	}
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int tmp; cin >> tmp;
		insert.push_back(tmp);
	}
	memset(dp, -1, sizeof(dp));
	sort(insert.begin(), insert.end());
	if (M > 0) cout << solve(0, 0, M-1, 0, 0) << "\n";
	else cout << solve(0, 1, 0, 0, 0) << "\n";
}

/*
Inspired by Wesley's pro solution

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3004;

vector<int> curr, insert;
int N, M;
ll dp[MAXN][104][104][2];

ll solve(int n, int s, int e, bool l) {
	if (n == N && s > e) return 0;
	if (dp[n][s][e][l] != -1) return dp[n][s][e][l];
	ll ans=0;

	if (n < N) ans = solve(n+1, s, e, 0);

	if (l && s <= e) ans = max(ans, solve(n, s+1, e, 0));
	else if (!l) {
		if (n < N) ans = max(ans, solve(n+1, s, e, 1) + curr[n]);
		if (e >= s) ans = max(ans, solve(n, s, e-1, 1)+insert[e]);
	}
	return dp[n][s][e][l] = ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp; cin >> tmp;
		curr.push_back(tmp);
	}
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int tmp; cin >> tmp;
		insert.push_back(tmp);
	}
	memset(dp, -1, sizeof(dp));
	sort(insert.begin(), insert.end());
	if (M > 0) cout << solve(0, 0, M-1, 0) << "\n";
	else cout << solve(0, 1, 0, 0) << "\n";
}
*/
