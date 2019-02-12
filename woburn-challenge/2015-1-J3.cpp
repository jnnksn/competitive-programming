// https://wcipeg.com/problem/wc151j3
#include <bits/stdc++.h>

using namespace std;

priority_queue<int> q;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/WC/input.txt", "r", stdin);
#endif
	int N; cin >> N;
	int ans = 10;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		ans += a;
		q.push(a);
	}
	ans += q.top(); q.pop();
	ans += q.top();
	cout << ans << "\n";
	return 0;
}
// READ
/*
Slow and easy wins the race (time should not matter).
Start Simple, solve easiest version
-------------------------------------------------------------------
1. Make sure you understand and don't miss anything!
2. Constraints && Time and memory limit
4. Problem Type ~ Don't get tricked! (Animal Farm, New Years P3)
5. Have I seen this problem before? What tricks can I use from previous problems? (PHO, CONVEX, KING GRUFF)
-------------------------------------------------------------------
*/

// DEBUG
/*
-------------------------------------------------------------------
1. long long instead of int
2. Missing something from problem
3. Proper output
4. Corner cases
5. Your solution is just wrong.
-------------------------------------------------------------------
*/
