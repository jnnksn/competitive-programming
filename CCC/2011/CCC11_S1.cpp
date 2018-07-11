// https://dmoj.ca/problem/ccc11s1
// 07/11/2018
// ----------------------------------------
// I guess I don't use getline too much...
// Aparently there could be trailing whitespace that messes up
// the input.. LOL. That was frustrating.
// ----------------------------------------

#include <iostream>
#include <string>
using namespace std;

string tmp;
int N, T, S;

int main() {
    cin >> N;
    for (int i = 0; i <= N; ++i) {
        getline(cin, tmp);
        for (int j = 0; j < tmp.length(); ++j) {
            if (tmp[j] == 'T' || tmp[j] == 't') T += 1;
            if (tmp[j] == 'S' || tmp[j] == 's') S += 1;
        }
    }
    if (T > S) cout << "English\n";
    else cout << "French\n";
}
