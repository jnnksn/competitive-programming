// https://dmoj.ca/problem/ecoo14r3p4
// 08/02/2018
// ------------------------------------
// Ayyyy I solved it! It seems that ECOO dp problems always have
// the same "concept"... 
// ------------------------------------

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[2004];

bool baby_word(string s) {
	if (s.length() % 2 > 0) return false;
	int k = s.length() / 2;
	return (s.substr(0, k) == s.substr(k, k));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 10;
	while (T--) {
		fill(dp, dp+2004, 0);
		int ans = 0;
		string phrase; cin >> phrase;
		int k = phrase.length();
		for (int i = 0; i <= k; ++i) {
			for (int j = 1; j <= k-i; ++j) {
				if (baby_word(phrase.substr(i, j))) {
					dp[i+j-1] = max(dp[i-1]+j, dp[i+j-1]);
					ans = max(ans, dp[i+j-1]);
				}
			}
		}
		cout << ans << "\n";
	}
}
