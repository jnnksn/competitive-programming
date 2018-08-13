#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ID[74];
vector<int> query;
int md, routes;
int main() {
	int T = 10;
	while (T--) {
		md = 2e9;
		cin >> routes;
		for (int i = 1; i <= routes; ++i) {
			int tmd = 2e9;
			int id, s; cin >> id >> s;
			query.push_back(id);
			for (int i = 1; i <= s; ++i) {
				int n; cin >> n;
				tmd = min(n, tmd);
			}
			ID[id] = tmd;
			md = min(tmd, md);
		}
		sort(query.begin(), query.end());
		vector<int> ansl;
		for (int i = 0; i < routes; ++i) {
			if (ID[query[i]] == md) {
				ansl.push_back(query[i]);
			}
		}
		cout << md << " {";
		for (int i = 0; i < ansl.size(); ++i) {
			if (i == ansl.size()-1) {
				cout << ansl[i] << "}\n";
			} else {
				cout << ansl[i] << ",";
			}
		}
		query.clear(); ansl.clear();
	}
}
