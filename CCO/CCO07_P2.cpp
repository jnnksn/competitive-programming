// https://dmoj.ca/problem/cco07p2
// 01/04/2019

#include <bits/stdc++.h>
using namespace std;

set< vector<int> > cnt;

vector<int> shift(vector<int> vec) {
	vector<int> tmp(6);
	for (int i = 0; i < 6; i++) {
		if (!i) {
			tmp[i] = vec[5];
			continue;
		}
		tmp[i] = vec[i-1];
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/__RUN__/input.txt", "r", stdin);
	freopen("/Users/huogenx/Desktop/__RUN__/output.txt", "w", stdout);
#endif
	int N; cin >> N;
	bool ans = true;
	for (int i = 0; i < N; i++) {
		vector<int> tmp(6);
		for (int j = 0; j < 6; j++) {
			cin >> tmp[j];
		}
		for (int j = 0; j < 6; j++) {
				vector<int> cpy = tmp;
				reverse(cpy.begin(), cpy.end());
				if (cnt.count(tmp) || cnt.count(cpy)) ans = false;
				else tmp = shift(tmp);
		}
		if (ans) cnt.insert(tmp);
	}
	cout << (ans ? "No two snowflakes are alike." : "Twin snowflakes found.") << "\n";
}
