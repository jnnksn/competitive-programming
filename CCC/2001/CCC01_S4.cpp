// https://dmoj.ca/problem/ccc01s4
// october

#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
};

double length(point a, point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

vector<point> coords;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	coords.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> coords[i].x >> coords[i].y;
	}
	double ans = 0.0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int n = j+1; n < N; n++) {
				double x = length(coords[i], coords[j]);
				double y = length(coords[i], coords[n]);
				double z = length(coords[j], coords[n]);
				if (x > y && x > z) {
					ans = max(ans, x);
				} else if (y > x && y > z) {
					ans = max(ans, y);
				} else if (z > x && z > y) {
					ans = max(ans, z);
				} else {
					double S = (x+y+z) / 2.0;
					double A = sqrt(S*(S-x)*(S-y)*(S-z));
					double D = (x*y*z)/(4.0*A)*2.0;
					ans = max(ans, D);
				}
			}
		}
	}
	cout << fixed << setprecision(2) << ans << "\n";
}
