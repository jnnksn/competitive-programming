#include <iostream>
using namespace std;

int main() {
	int t = 10;
	while (t--) {
		int T, N; cin >> T >> N;
		bool has_box = 0;
		int count_days = 0, queue = 0;
		for (int i = 0; i < N; ++i) {
			char box; cin >> box;
			if (box == 'B') {
				if (!has_box) has_box = 1;
				else queue += 1;
			}

			if (count_days == T) {
				count_days = 0;
				has_box = 0;
				if (queue > 0) {
					has_box = 1;
					queue--;
				}
			}

			if (has_box) count_days++;

		}
		int ans = (count_days == 0 ? 0 : T-count_days) + (queue*T);
		cout << ans << "\n";

	}
}
