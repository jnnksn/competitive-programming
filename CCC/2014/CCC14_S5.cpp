// https://dmoj.ca/problem/ccc14s5
// 05/31/2018
// -------------------------------
// Thanks to http://mmhs.ca/ccc/2014/2014s5jacobjackson.txt
// for the hints! Although still took me forever even with the hints...
// COOL THINGS I'VE LEARNED:
// I never knew you could utilise structs like this!
// I also never knew you could customize your sort function so easily!
// LOTS of stackoverflow + searching for this stuff..... But worth it 
// in the end!
// I may want to add some of these in my CP Template!
// Another thing to mention was how distance was calculated!
// There was no need to use square root when finding the distances
// it is just an additional step that is unnecessary!
//
// Luckily, the algorithm for this problem was easy to get after the
// MANY hints I took... LOL.
// -------------------------------

#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <string>

#define FOR(x,y,z) for(int x = y; x < z; ++x)
#define ALL(x) x.begin(), x.end()
#define INF 2000000000
#define EACH(x, y) for (auto x : y)
#define IN(x,y) find(ALL(x), y)
using namespace std;

struct Triple {int one, two, thr;};

int DP[2001], prevs[2001], currDist[2001], N, x, y, a, b, d;
vector<pair<int, int>> points = {{0,0}};
vector<Triple> dists;

bool compare(const Triple &a, const Triple &b) {
    return b.one > a.one;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    
    cin >> N;
    FOR(_, 0, N) {
        cin >> x >> y;
        points.push_back({x,y});
    }
    
    // find dists
    FOR(i, 0, N+1) {
        FOR(j, i+1, N+1) {
            int dX = points[i].first - points[j].first;
            int dY = points[i].second - points[j].second;
            dists.push_back({dX*dX+dY*dY, i, j});
           
        }
    }
    
    sort(ALL(dists), compare);
   
    
    FOR(i, 0, dists.size()) {
        
        d = dists[i].one; a = dists[i].two; b = dists[i].thr;
        
        if (d > currDist[a]) {
            currDist[a] = d;
            prevs[a] = DP[a];
        }
        
        if (d > currDist[b]) {
            currDist[b] = d;
            prevs[b] = DP[b];
        }
        
        if (a == 0) DP[0] = max(DP[0], prevs[b]+1);
        else {
            DP[a] = max(DP[a], prevs[b]+1);
            DP[b] = max(DP[b], prevs[a]+1);
        }
        
    }
    
    cout << DP[0] << "\n";
    
}
