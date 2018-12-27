// https://dmoj.ca/problem/ccc14s4
// 12/27/2018
/*
Not my proudest implementation.
We notice that the coordinate grid can be 1e9 by 1e9, thus a normal 2d array would not be able to store it.
However, N is at most 1000, thus there would only be at most 2000 x coordinates and 2000 y coordinates.
Using this, we compress the coordinates by putting them in arrays separated by x's and y's. 
After this, we won't be needing duplicates anymore, so we remove them and then sort the arrays.
Now that we know all the x values and y values, we can label each distinct x and y coordinate with a
number between 0 to N-1
This is us compressing the coordinates into a range of 0-(N-1).

Next, we use a difference array by performing the following for each rectangle:
1. Add the tint factor to the left edge of the rectangle.
2. Subtract the tint factor from the right edge of the rectangle.

Then, we can access the difference array in order to get the final tint factors. However, we remember
that the coordinates were compressed, and to get the actual area, we can calculate it by adding the
area of the square pocket with that specific tint factor: deltaY*deltaX.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Rect {
	ll x1, y1, x2, y2, t;
};

vector<Rect> rects;
vector<ll> sortX, sortY;
map<ll, ll> dictX, dictY;

ll da[2004][2004];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/__RUN__/input.txt", "r", stdin);
#endif
	ll N, T; cin >> N >> T;
	rects.resize(N);
	for (ll i = 0; i < N; i++) {
		cin >> rects[i].x1 >> rects[i].y1;
		cin >> rects[i].x2 >> rects[i].y2 >> rects[i].t;
		sortX.push_back(rects[i].x1);
		sortX.push_back(rects[i].x2);
		sortY.push_back(rects[i].y1);
		sortY.push_back(rects[i].y2);
	}
	sortX.erase(unique(sortX.begin(), sortX.end()), sortX.end());
	sortY.erase(unique(sortY.begin(), sortY.end()), sortY.end());
	sort(sortX.begin(), sortX.end());
	sort(sortY.begin(), sortY.end());

    for (int i = 0; i < sortX.size(); i++) {
        dictX[sortX[i]] = i;
    }
     for (int i = 0; i < sortY.size(); i++) {
        dictY[sortY[i]] = i;
    }
	for (int i = 0; i < N; i++) {

		for (int j = dictY[rects[i].y1]; j < dictY[rects[i].y2]; j++) {

			da[j][dictX[rects[i].x1]] += rects[i].t;
			da[j][dictX[rects[i].x2]] -= rects[i].t;
		}
	}

	ll ans = 0;
	for (ll i = 0; i < sortY.size()-1; i++) {
		for (ll j = 0; j < sortX.size()-1; j++) {
			da[i][j+1] += da[i][j];
			if (da[i][j] >= T) {
				ans += (sortY[i+1] - sortY[i]) * (sortX[j+1] - sortX[j]);
			}
		}
	}

	cout << ans << "\n";

}
