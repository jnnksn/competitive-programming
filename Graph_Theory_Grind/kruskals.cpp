#include <iostream>
#include <set>
using namespace std;

const int MAXN = 6;

int N, x, y, z;
set<pair<int, pair<int, int>>> EW;
int link[MAXN+1], sizes[MAXN+1];


int find(int x) {
	while (x != link[x]) x = link[x];
	return x;
}

bool same(int e, int r) {
	return find(e) == find(r);
}

void unite(int e, int r) {
	e = find(e); r = find(r);
	if (sizes[e] < sizes[r]) swap(e, r);
	sizes[e] += sizes[r];
	link[r] = e;
}

void solve() {
	for (auto x : EW) {
		int a = x.second.first, b = x.second.second;
		if (!same(a, b)) unite(a, b);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < 8; ++i) {
		cin >> x >> y >> z;
		EW.insert({z, {x, y}});
	}

	for (int i = 1; i <= MAXN; ++i) {
		link[i] = i; sizes[i] = 1;
	}

	solve();

	for (int i = 1; i <= MAXN; ++i) {
		cout << link[i] << "\n";
	}

}
