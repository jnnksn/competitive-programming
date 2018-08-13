#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T = 10;
	while (T--) {
		int n, x, y, z; cin >> n >> x >> y >> z;
		vector<string> decode;
		for (int i = 0; i < n; ++i) {
			string phrase; cin >> phrase;
			string new_phrase = "";
			for (int j = 0; j < phrase.length(); ++j) {
				int a = phrase[j] - '0';
				if (a == 0) {
					new_phrase += to_string(z);
				} else if (a % 2 == 0) {
					new_phrase += to_string(a+x);
				} else {
					int b = (a-y < 0 ? 0 : a-y);
					new_phrase += to_string(b);
				}
			}
			decode.push_back(new_phrase);
		}
		char tmp; cin >> tmp;
		vector<int> fail;
		bool match = 1;
		for (int i = 0; i < n; ++i) {
			string dc; cin >> dc;
			if (dc != decode[i]) {
				match = 0;
				fail.push_back(i+1);
			}
		}
		if (match) cout << "MATCH" << "\n";
		else {
			sort(fail.begin(), fail.end());
			cout << "FAIL: ";
			for (int i = 0; i < fail.size(); ++i) {
				if (i == fail.size()-1) cout << fail[i] << "\n";
				else cout << fail[i] << ",";
			}
		}
		cin >> tmp;
	}
}
