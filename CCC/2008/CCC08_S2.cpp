// https://dmoj.ca/problem/ccc08s2
// 08/28/2018
// -------------------------------------------
// The Algorithm:
// We know that all points which lie on the edge of a circle obey X^2 + Y^2 = R^2, where X and Y are the coordinates
// R is the radius. So, this means that for any X^2 + Y^2 <= R^2, it is in the circle.
// We know that any negatives squared is positive, thus checking all quadrants wastes time since the number of pennies in
// quadrant 1 will be the same in all quadrants, meaning we only need to check quadrant 1.
// Another way to reduce time is to keep track of which X values have already been found. I iterate from the highest Y value (R)
// downwards, thus if we find a point that lies in the circle at a given X, the Y value is the highest. Let HY represent the 
// highest Y value at that X. Knowing HY means that for each (HY-1) Y value for that X is also within the circle. So once found
// we can just add HY to our total pennies, and we never have to check that X again.
// Note that we do not check coordinates with X or Y value during this.
//
// Next we account for all quadrants, which is (# of pennies in quad. 1) * 4
// We know that the highest X when Y = 0 is R, and highest Y when X = 0 is R, since:
// R^2 + 0^2 = R^2
// Then we account for (0, 0).
// This results in the following result:
// ((# of pennies in quad. 1) * 4) + (R * 4) + 1
// -------------------------------------------

#include <bits/stdc++.h>
using namespace std;

const int MAXR = 25004;

int vis[MAXR];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		int ans = 0;
		memset(vis, 0, sizeof(vis));
		int R; cin >> R;
		if (R == 0) break;
		int rsq = pow(R, 2);
		for (int y = R; y >= 1; --y) {
			for (int x = 1; x <= R; ++x) {
			    if (vis[x]) continue;
				if (pow(x, 2) + pow(y, 2) <= rsq) {
					ans += y;
					vis[x] = 1;
				}
			}
		}
		cout << (ans*4) + (R*4) + 1 << "\n";
	}

}
