// https://dmoj.ca/problem/ccc02s1
// october

#include <bits/stdc++.h>
using namespace std;

struct vis {
	int a, b, c, d;
};

int total, ans1 = 0, ans2 = 1e6;
int price[5];
bool mem[20][20][20][20];

void solve(int a, int b, int c, int d, int t) {
	if (t > total) return;
	if (t == total) {
		if (mem[a][b][c][d]) return;
		mem[a][b][c][d] = true;
		cout << "# of PINK is " << a << " # of GREEN is " << b << " # of RED is " << c << " # of ORANGE is " << d << "\n";
		ans1++;
		ans2 = min(ans2, a+b+c+d);
	}
	solve(a+1, b, c, d, t+price[1]);
	solve(a, b+1, c, d, t+price[2]);
	solve(a, b, c+1, d, t+price[3]);
	solve(a, b, c, d+1, t+price[4]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> price[1] >> price[2] >> price[3] >> price[4];
	cin >> total;
	solve(0, 0, 0, 0, 0);
	cout << "Total combinations is " << ans1 << ".\n";
	cout << "Minimum number of tickets to print is " << ans2 << ".\n";
}
