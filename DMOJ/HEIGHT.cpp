// https://dmoj.ca/problem/rgss4
// 07/31/2018
// O(n^2) approach

#include <iostream>
#include <algorithm>
using namespace std;

int DP[1004], height[1004];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int ans = -1;
	for (int i = 0; i < n; ++i) cin >> height[i];
	for (int i = 0; i < n; ++i) {
		DP[i] = height[i];
		for (int j = 0; j < i; ++j) {
			if (height[i] > height[j]) {
				DP[i] = max(DP[i], DP[j]+height[i]);
			}
		}
		ans = max(ans, DP[i]);
	}
	cout << ans << "\n";
}
