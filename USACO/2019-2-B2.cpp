#include <bits/stdc++.h>

using namespace std;

bool sorted(vector<int> cows) {
	for (int i = 0; i < cows.size()-1; i++) {
		if (cows[i] < cows[i+1]) continue;
		return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/run/input.txt", "r", stdin);
#else
  freopen("sleepy.in", "r", stdin);
  freopen("sleepy.out", "w", stdout);
#endif
	vector<int> cows;

	int N; cin >> N;
	cows.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> cows[i];
	}
	int ans = 0;
	while (!sorted(cows)) {
		ans++;
		/*
		for (auto u : cows) {
			cout << u;
		}
		cout << "\n";
		*/
		vector<int> tmp;
		int ind = -1;
		for (int i = N-1; i > 1; i--) {
			if (cows[0] > cows[i]) {
				ind = i+1;
				break;
			}
			if (cows[0] < cows[i] && cows[i] < cows[i-1]) {
				ind = i;
				break;
			}
			if (cows[0] == cows[i]-1) {
				ind = i;
				break;
			}
		}
		if (ind == -1) ind = N - 1;
		//if (cows[0] == N) ind = N;
		//if (cows[0] == N) ind = N;

		for (int i = 1; i < ind; i++) {
			tmp.push_back(cows[i]);
		}
		tmp.push_back(cows[0]);
		for (int i = ind; i < N; i++) {
			tmp.push_back(cows[i]);
		}
		cows = tmp;
	}
	cout << ans << "\n";
}
