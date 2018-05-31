// https://dmoj.ca/problem/ccc02s4
// 05/30/2018
// -------------------------------
// Remember to reset groups when
// lower time is found! Otherwise
// you will just be adding on
// do the previous time's group's
// names.
// -------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define FOR(x,y,z) for(int x = y; x < z; ++x)
#define ALL(x) x.begin(), x.end()
#define INF 2000000000
#define EACH(x, y) for (auto x : y)
#define IN(x,y) find(ALL(x), y)

using namespace std;


int max_size, N, DP[101], times[101];
string names[101];
vector<string> groups[101];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> max_size >> N;
    FOR(i, 1, N+1) {
        cin >> names[i] >> times[i];
    }


    
    FOR(i, 1, N+1) {
        DP[i] = INF;
    }
    DP[0] = 0;
    FOR(i, 1, N+1) {
        FOR(j, 0, max_size) {
            int BIG = -1;
            FOR(x, i, i+j+1) BIG = max(BIG, times[x]);
            if (DP[i-1] + BIG < DP[i+j]) {
                DP[i+j] = DP[i-1] + BIG;
                groups[i+j].clear();
                FOR (x, 0, groups[i-1].size()) groups[i+j].push_back(groups[i-1][x]);
                FOR(x, i, i+j+1) groups[i+j].push_back(names[x]);
                groups[i+j].push_back("break");

            }
        }
    }
    cout << "Total Time: " << DP[N] << "\n";
    FOR(i, 0, groups[N].size()) {
        if (groups[N][i] == "break") {
            cout << "\n";
            continue;
        }
        cout << groups[N][i] << " ";
    }
}
