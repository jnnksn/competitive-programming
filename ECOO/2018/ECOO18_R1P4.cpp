#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 48; // Fib gets pretty big by now?
typedef long long ll;

struct Square {
	ll l, r, t, b;
};

ll dp[MAX];

vector<Square> nSquare;
int moveX[4] = {-1, -1, 1, 1};
int moveY[4] = {-1, 1, 1, -1};

// 0 = down, 1 = left, 2 = up, 3 = right
void gen() {
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i < MAX; ++i) dp[i] = dp[i-1] + dp[i-2];
	ll x = 1, y = 0, shift = 0;
	for (int i = 0; i < MAX; ++i) {
		Square sq;
		sq.l = x;
		sq.b = y;
		x += dp[i] * moveX[shift];
		y += dp[i] * moveY[shift];
		sq.r = x;
		sq.t = y;
		if (sq.l > sq.r) swap(sq.l, sq.r);
		if (sq.b > sq.t) swap(sq.b, sq.t);
		shift = (shift+1) % 4;
		nSquare.push_back(sq);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	gen();
	int T = 10;

	while (T--) {
		int x, y; cin >> x >> y;
		for (int i = 1; i < MAX; ++i) {
			if (nSquare[i].l <= x && x <= nSquare[i].r && nSquare[i].b <= y && y <= nSquare[i].t) {
				cout << i << "\n";
				break;
			}
		}
	}

}
