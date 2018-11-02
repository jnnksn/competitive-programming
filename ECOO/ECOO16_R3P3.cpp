// https://dmoj.ca/problem/ecoo16r3p3
// 08/01/2018
//include <bits/stdc++.h>
using namespace std;

set<string> word;
int dp[2004];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifdef _DEBUG
		freopen("/Users/huogenx/Desktop/__RUN__/input.txt", "r", stdin);
	#endif
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string w; cin >> w;
		//word[w] = 1;
		word.insert(w);
	}
	int T = 10;
	while (T--) {
		fill(dp, dp+2004, 2004);

		string phrase; cin >> phrase;
		int len = phrase.length();

		for (int i = 0; i < len; i++) {
			for (int j = 1; j <= len-i; j++) {
				if (word.count(phrase.substr(i, j))) {
					if (i == 0) {
						dp[i+j-1] = 1;
					} else {
						dp[i+j-1] = min(dp[i+j-1], dp[i-1]+1);
					}
				}
			}
		}
		cout << dp[len-1]-1 << "\n";
	}
}
