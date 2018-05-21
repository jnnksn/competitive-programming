// https://dmoj.ca/problem/ccc07s5
// 05/20/2018
// -------------------------------
// Got help from: http://mmhs.ca/ccc/2007/CCC2007S5BowlingForNumbersDP.txt
// Since I still suck :/ 
// One thing to remember is to RESET everything after each test case!
// -------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define REP(x,y,z) for(int x = y; x < z; ++x)
#define ALL(x) x.begin(), x.end()
#define INF 2000000000
#define EACH(x, y) for (auto x : y)
#define IN(x,y) find(ALL(x), y)

using namespace std;
int TC, n_pins, n_balls, w, pins[30001];
long long DP[501][30001], sums[30001] = {0};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--) {
        
        // INPUT
        cin >> n_pins >> n_balls >> w;
        REP(i, 0, n_pins) {
            cin >> pins[i];
        }
        // RESET SUMS
        REP(i, 0, n_pins) sums[i] = 0;
        // INITIAL SUMS
        REP(i, 0, n_pins) {
            REP(j, 0, w) {
                if (i+j >= n_pins) break;
                sums[i] += pins[i+j];
            }
        }
       
        // SET ALL TOTALS TO 0 WHEN N_BALLS = 0
        REP(i, 0, n_pins) DP[0][i] = 0;
        //REP(i, 1, n_balls+1) REP(j, 0, n_pins) DP[i][j] = -1;

        // FILL DP
        REP(i, 1, n_balls+1) {
            for(int j = n_pins-1; j > -1; --j ) {
                if (j+w >= n_pins) DP[i][j] = sums[j];
                else DP[i][j] = max(DP[i-1][j+w] + sums[j], DP[i][j+1]);
            }
        }
        
        cout << DP[n_balls][0] << "\n";
    }
}
