// https://dmoj.ca/problem/ccc10s1
// 04/19/2018

#include <bits/stdc++.h>
#define loop(x,y,z) for(int x = y; x < z; ++x)
#define all(x) x.begin(), x.end()
using namespace std;

int N;
string name;
int RAM, CPU, space;
vector<int> totals;
vector<string> names;
int main() {
    cin >> N;
    loop(i, 0, N) {
        cin >> name >> RAM >> CPU >> space;
        names.push_back(name);
        totals.push_back((2 * RAM) + (3 * CPU) + space);
    }

    int big = 0, indexed;
    loop(i, 0, N) {
        if (totals[i] > big) {
            big = totals[i];
            indexed = i;
        }
    }
    if (N == 1) cout << names[indexed];
    if (totals.size() > 1) {
        int biggest = 0;
        int indextwo;
        loop(i, 0, N) {
            if (totals[i] > biggest && i != indexed) {
                biggest = totals[i];
                indextwo = i;
            }
        }
        if (biggest == big) {
            vector<string> c;
            c.push_back(names[indexed]);
            c.push_back(names[indextwo]);
            sort(all(c));
            cout << c[0] << "\n" << c[1];
        } else {
            cout << names[indexed] << "\n" << names[indextwo];
        }
    }
}

