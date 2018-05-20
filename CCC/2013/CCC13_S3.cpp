// https://dmoj.ca/problem/ccc13s3
// 05/20/2018
// -------------------------------
// There are 6 possible matchups since each team plays eachother only once:
// 1v2, 1v3, 1v4, 2v3, 2v4, and 3v4
// Thus, we generate all possible matchups.
//
// Initially I looked to store each possible combination in its own array,
// however it seems that vectors don't store arrays.
// Then I realized I didn't even need to use a vector, but it was
// too late, and I had already switched to using strings.
// I planned to use a vector to memoize the recursion, checking whether
// a combination has been made before. I soon discovered that there was no
// point since it is guaranteed that each generated combination will be unique.
//
// An iterative solution could be easily done, instead of a recursive apporach.
// Since each unknown game has 3 different outcomes, we should be able to
// count the number of unknown games, then iteratively generate the outcomes.
// BUT IDK BECAUSE I DIDN'T DO THAT.
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

// LOL REALIZED VECTORS CAN'T STORE ARRAYS, SO I SWITCHED TO STRINGS
string GAME = "......";

int FAV, G, X, Y, sX, sY, total = 0;

bool WIN(string str) {
    int scores[4] = {0,0,0,0};
    if (str[0] == 'W') scores[0] += 3;
    else if (str[0] == 'L') scores[1] += 3;
    else {scores[0] += 1; scores[1] += 1;}

    if (str[1] == 'W') scores[0] += 3;
    else if (str[1] == 'L') scores[2] += 3;
    else {scores[0] += 1; scores[2] += 1;}

    if (str[2] == 'W') scores[0] += 3;
    else if (str[2] == 'L') scores[3] += 3;
    else {scores[0] += 1; scores[3] += 1;}

    if (str[3] == 'W') scores[1] += 3;
    else if (str[3] == 'L') scores[2] += 3;
    else {scores[1] += 1; scores[2] += 1;}

    if (str[4] == 'W') scores[1] += 3;
    else if (str[4] == 'L') scores[3] += 3;
    else {scores[1] += 1; scores[3] += 1;}

    if (str[5] == 'W') scores[2] += 3;
    else if (str[5] == 'L') scores[3] += 3;
    else {scores[2] += 1; scores[3] += 1;}
    
    int largest = -1, winner = -1, tie = -1;
    REP(i, 0, 5) {
        if (scores[i] >= largest) {
            tie = largest;
            winner = i;
            largest = scores[i];
        }
    }
    
    if (winner == FAV-1 && largest > tie) return true;
    else return false;
}
bool simulate(string res) {
    if (res.find('.') != string::npos) {
        REP(i, 0, 6) {
            if (res[i] == '.') {
                res[i] = 'W';
                simulate(res);
                res[i] = 'L';
                simulate(res);
                res[i] = 'T';
                simulate(res);
                break;
            }
        }
    } else {
        if(WIN(res)) {
            total += 1;
        }
        return true;
    }

    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> FAV >> G;
    REP(_, 0, G) {
        cin >> X >> Y >> sX >> sY;
        // OUTCOME
        if (X == 1 && Y == 2) {
            if (sX > sY) GAME[0] = 'W';
            else if (sX < sY) GAME[0] = 'L';
            else GAME[0] = 'T';
        } else if (X == 1 && Y == 3) {
            if (sX > sY) GAME[1] = 'W';
            else if (sX < sY) GAME[1] = 'L';
            else GAME[1] = 'T';
        } else if (X == 1 && Y == 4) {
            if (sX > sY) GAME[2] = 'W';
            else if (sX < sY) GAME[2] = 'L';
            else GAME[2] = 'T';
        } else if (X == 2 && Y == 3) {
            if (sX > sY) GAME[3] = 'W';
            else if (sX < sY) GAME[3] = 'L';
            else GAME[3] = 'T';
        } else if (X == 2 && Y == 4) {
            if (sX > sY) GAME[4] = 'W';
            else if (sX < sY) GAME[4] = 'L';
            else GAME[4] = 'T';
        } else if (X == 3 && Y == 4) {
            if (sX > sY) GAME[5] = 'W';
            else if (sX < sY) GAME[5] = 'L';
            else GAME[5] = 'T';
        }
    }
    simulate(GAME);
    cout << total << "\n";
}
