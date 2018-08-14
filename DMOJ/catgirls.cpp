#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 500004;

ll dp[MAXN], w[MAXN], c[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll ind = 1;
	ll N, W; cin >> N >> W;
	for (int i = 0; i < N; ++i) {
		char x; cin >> x;
		if (x == 'A') {
			int t, y; cin >> t >> y;
			w[ind] = t + w[ind-1];
			c[ind] = y + c[ind-1];
			ll a = 1, b = ind;
      // I don't think I can use lowerbound?
			while (a <= b) {
				ll mid = (a+b)/2;
				ll width = w[ind] - w[mid-1];
				if (width <= W) b = mid-1;
				else a = mid+1;
			}
      
			dp[ind] = max(dp[ind-1], c[ind]-c[b]);
			cout << dp[ind] << "\n";
			ind++;
		} else ind--;
	}

}
