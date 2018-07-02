// http://codeforces.com/contest/999/problem/A
// 07/02/2018

#include <iostream>
#include <vector>
using namespace std;

int n, k, x, ans=0;
vector<int> list;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		list.push_back(x);
	}

	int f = 0, b = list.size()-1;
	int phail = 0;
	while (true) {
		phail = 0;
		if (list[f] <= k) {
			f++;
			ans++;
			phail++;
		}

		if (list[b] <= k && f < b) {
			b--;
			ans++;
			phail++;
		}

		if (phail==0) break;
		if (f > b) break;

	}

	cout << ans << "\n";

}
