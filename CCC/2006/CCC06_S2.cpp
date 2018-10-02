// https://dmoj.ca/problem/ccc06s2
// 08/28/2018

#include <bits/stdc++.h>
using namespace std;

map<char, char> translate;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string ptxt; getline(cin, ptxt);
	string ctxt; getline(cin, ctxt);
	for (int i = 0; i < ptxt.size(); ++i) {
		translate[ctxt[i]] = ptxt[i];
	}
	string cipher; getline(cin, cipher);
	for (int i = 0; i < cipher.size(); ++i) {
		if (translate.count(cipher[i]) == 0) cout << ".";
		else cout << translate[cipher[i]] << "";
	}

}
