// https://dmoj.ca/problem/ccc07s2
// 08/28/2018
// ---------------------------------------
// Note: 
// I SUCK! At first I thought you could determine if a box could fit by face size and length...
// use long long and 8e9...
//
// The Algorithm:
// I'm not sure, but I just went with 3! (6) possibilities for dimensions.
// Essentially we find all combinations of the dimensions for each box.
// We do the same for each object and then do two nested for loops to check if there is a box and item, where
// the item's dimensions are <= to the box dimensions. If so, check if it is the smaller box.
// 
// ---------------------------------------

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct REEEEE {
	int l, w, h;
};

vector<REEEEE> dim[1003];
ll size[1003];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	for (int i = 1; i <= N; ++i) {
		int a, b, c; cin >> a >> b >> c;
		size[i] = a * b * c;
		dim[i].push_back({a, b, c});
		dim[i].push_back({c, b, a});
		dim[i].push_back({b, c, a});
		dim[i].push_back({a, c, b});
		dim[i].push_back({c, a, b});
		dim[i].push_back({b, a, c});
	}

	int M; cin >> M;
	for (int i = 1; i <= M; ++i) {
		int a, b, c; cin >> a >> b >> c;
		vector<REEEEE> box;
		box.push_back({a, b, c});
		box.push_back({c, b, a});
		box.push_back({b, c, a});
		box.push_back({a, c, b});
		box.push_back({c, a, b});
		box.push_back({b, a, c});
		ll ans = 8e9;
		for (auto b : box) {
			// l, w, h
			for (int j = 1; j <= N; ++j) {
				for (auto d : dim[j]) {
					if (b.l <= d.l && b.w <= d.w && b.h <= d.h) {
						ans = min(ans, size[j]);
						break;
					}
				}
			}
		}
		if (ans == 8e9) cout << "Item does not fit.\n";
		else cout << ans << "\n";
	}

}
