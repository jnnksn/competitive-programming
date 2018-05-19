// https://dmoj.ca/problem/ccc16s4
// 05/19/2018
// -------------------------------
// I swear I didn't copy:
// https://amorim.ca/display/CS/Combining+Rice+Balls
// @AndrewDongAndy -> Thanks for giving me the resource :D
// -------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define REP(x,y,z) for(int x = y; x < z; ++x)
#define ALL(x) x.begin(), x.end()
#define INF 2000000000
#define EACH(x, y) for (auto x : y)
#define IN(x,y) find(ALL(x), y)

int num_balls, riceBalls[400], DP[400][400];

// HELPER FUNCTIONS
void add_sol(int s, int e, int c) {
    DP[s][e] = c;
}

bool possible(int s, int e) {
    if (s == e) return true;
    return DP[s][e] != -1;
}

int find(int s, int e) {
    if (s == e) return riceBalls[s];
    return DP[s][e];
}

bool find_two(int fs, int le) {
    REP(ls, fs+1, le+1) {
        int fe = ls-1;
        // following cannot be combined
        // start index is constant | last index dynamic ==> typeOne
        if (!possible(fs, fe)) continue;
        // start index is dynamic | last index static ==> typeTwo
        if (!possible(ls, le)) continue;
        // find total typeOne
        int f = find(fs, fe);
        // find total typeTwo
        int l = find(ls, le);
        if (f != l) continue;        
        // find total after combining
        int total = l * 2;
        add_sol (fs, le, total);
        // only need 1 sol
        return true;
    }
    return false;
}

// FS <= first block section => FE | MS <= middle block section => ME | LS <= last block section => LE
// If total of all blocks in first section == total of all blocks in last section. We can combine.
void find_three(int fs, int le) {
    REP(ms, fs+1, le) {
        // end of first block section
        int fe = ms-1;
        // if first block section cannot be combined, skip
        if (!possible(fs, fe)) continue;
        int f = find(fs, fe);
        REP(ls, ms+1, le+1) {
            // end of middle block section
            int me = ls-1;
            if (!possible(ms, me)) continue;
            if (!possible(ls, le)) continue;
            int l = find(ls, le);
            if (f != l) continue;
            int m = find(ms, me);
            int total = f + m + l;
            add_sol(fs, le, total);
            return;
        }
    }
}

int main() {
     ios::sync_with_stdio(false); cin.tie(0);
     // INPUT
    cin >> num_balls;
    REP(i, 0, num_balls) cin >> riceBalls[i];
    // FILL 
    REP(i, 0, num_balls) REP(j, 0, num_balls) DP[i][j] = -1;
    
    // SEARCH
    REP(i, 2, num_balls+1) {
        int maxStart = num_balls-i+1;
        REP(fs, 0, maxStart) {
            int le = fs + i - 1;
            bool found = find_two(fs, le);
            if (found) continue;
            if (i > 2) find_three(fs, le);
        }
    }

    // FIND LARGEST COMBINATION
    int largest = 0;

    REP(i, 0, num_balls) REP(j, 0, num_balls) {
        if (DP[i][j] > largest) largest = DP[i][j];
        if (i == j) if (riceBalls[i] > largest) largest = riceBalls[i];
    }
    cout << largest << "\n";
}
