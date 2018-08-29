// https://dmoj.ca/problem/ccc06s1
// 08/28/2018

#include <bits/stdc++.h>
using namespace std;

bool dad[6][3], mom[6][3];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i <= 5; ++i) {
		char a, b; cin >> a >> b;
		if (isupper(a) || isupper(b)) dad[i][1] = 1;
		if (islower(a) || islower(b)) dad[i][2] = 1;
	}
	for (int i = 1; i <= 5; ++i) {
		char a, b; cin >> a >> b;
		if (isupper(a) || isupper(b)) mom[i][1] = 1;
		if (islower(a) || islower(b)) mom[i][2] = 1;
	}
	int T; cin >> T;
	while (T--) {
		int work = 0;
		for (int i = 1; i <= 5; ++i) {
			char gene; cin >> gene;
			if (isupper(gene)) {
				if (dad[i][1] || mom[i][1]) work++;
			} else {
				if (dad[i][2] && mom[i][2]) work++;
			}
		}
		if (work==5) cout << "Possible baby.\n";
		else cout << "Not their baby!\n";
	}
}
