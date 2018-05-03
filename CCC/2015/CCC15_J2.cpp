// https://dmoj.ca/problem/ccc15j2
// 05/02/2018

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string in;
int h = 0, s = 0;
int main() {
    getline(cin, in);
    for (int i = 0; i < in.size()-2; ++i) {
        if (in[i] == ':' && in[i+1] == '-' && in[i+2] == ')') h += 1;
        if (in[i] == ':' && in[i+1] == '-' && in[i+2] == '(') s += 1;
    }
    if (h > s) cout << "happy\n";
    else if (s > h) cout << "sad\n";
    else if (s == 0 && h == 0) cout << "none\n";
    else if (s == h) cout << "unsure\n";
}
