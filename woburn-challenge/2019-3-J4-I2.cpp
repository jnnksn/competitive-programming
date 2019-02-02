#include <bits/stdc++.h>

using namespace std;

#define MAXN 100004

typedef long long ll;

ll M[MAXN], G[MAXN];
ll N, S, LVL;
vector<ll> left1;
vector<ll> right1;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/WC/input.txt", "r", stdin);
#endif
  cin >> N >> S >> LVL;

	for (ll i = 0; i < N; i++) {
		ll p, x, d;
		cin >> p >> x >> d;
		M[p] = x;
		G[p] = d;
		if (p >= S) right1.push_back(p);
		else {
			left1.push_back(-p);
		}
	}
	sort(left1.begin(), left1.end());
	sort(right1.begin(), right1.end());
	reverse(left1.begin(), left1.end());
	reverse(right1.begin(), right1.end());

	while (true) {

		if (left1.size() > 0 && LVL >= M[-left1.back()]) {
			LVL += G[-left1.back()];
			left1.pop_back();
		} else if (right1.size() > 0 && LVL >= M[right1.back()]){
			LVL += G[right1.back()];
			right1.pop_back();
		} else {
			break;
		}
	}
	cout << LVL << "\n";
	return 0;
}
