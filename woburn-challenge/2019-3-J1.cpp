#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("/Users/huogenx/Desktop/WC/input.txt", "r", stdin);
#endif
	int P, B, D;
	cin >> P >> B >> D;
	cout << (int) (P / B)*D + (P%B) << "\n";
	return 0;
}
