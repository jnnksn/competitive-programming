// 03/22/2018
// https://dmoj.ca/problem/ccc08s1

#include <bits/stdc++.h>
#define REP(x,y,z) for(int x = y; x <= z; ++x)
#define ALL(x) x.begin(), x.end()
#define INF (int)1e9
#define EACH(x, y) for (auto x : y)
#define IN(x,y) find(ALL(x), y)
using namespace std;

string city, bigN;
int temp, big = 201;


int main() {
    while (true) {
        cin >> city >> temp;
        if (temp < big) {big = temp; bigN = city;}
        if (city == "Waterloo") break;
    }
    cout << bigN << "\n";
}
