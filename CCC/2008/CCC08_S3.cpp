// https://dmoj.ca/problem/ccc08s3
// 06/04/2018
// -------------------------------
// LOL... Exact same as robothieves.
// I swear!
// -------------------------------

#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const long long MAXN = 2000000000;
int R, C, T, dists[41][41], x, y;
char graph[41][41];
queue<pair<int, int>> q;

int BFS() {
    q.push({1,1});
    dists[1][1] = 1;
    while (!q.empty()) {
        tie(y, x) = q.front(); q.pop();
        //if (graph[y][x] == '*') continue;
        // left -- right [-]
        if (graph[y][x] == '-') {
            if (dists[y][x] + 1 < dists[y][x+1] && x+1 <= C && graph[y][x+1] != '*') {
                q.push({y, x+1});
                dists[y][x+1] = dists[y][x] + 1;
            }
            
            if (dists[y][x] + 1 < dists[y][x-1] && x-1 > 0 && graph[y][x-1] != '*') {
                q.push({y, x-1});
                dists[y][x-1] = dists[y][x] + 1;
            }
            
            continue;
        }
        
        // up -- down [|]
        if (graph[y][x] == '|') {
            if (dists[y][x] + 1 < dists[y+1][x] && y+1 <= R && graph[y+1][x] != '*') {
                q.push({y+1, x});
                dists[y+1][x] = dists[y][x] + 1;
            }
            
            if (dists[y][x] + 1 < dists[y-1][x] && y-1 > 0 && graph[y-1][x] != '*') {
                q.push({y-1, x});
                dists[y-1][x] = dists[y][x] + 1;
            }
            
            continue;
            
        }
        
        // left -- right -- up -- down [+]
        
        if (graph[y][x] == '+') {
            if (dists[y][x] + 1 < dists[y][x+1] && x+1 <= C && graph[y][x+1] != '*') {
                q.push({y, x+1});
                dists[y][x+1] = dists[y][x] + 1;
            }
            
            if (dists[y][x] + 1 < dists[y][x-1] && x-1 > 0 && graph[y][x-1] != '*') {
                q.push({y, x-1});
                dists[y][x-1] = dists[y][x] + 1;
            }
            
            if (dists[y][x] + 1 < dists[y+1][x] && y+1 <= R && graph[y+1][x] != '*') {
                q.push({y+1, x});
                dists[y+1][x] = dists[y][x] + 1;
            }
            
            if (dists[y][x] + 1 < dists[y-1][x] && y-1 > 0 && graph[y-1][x] != '*') {
                q.push({y-1, x});
                dists[y-1][x] = dists[y][x] + 1;
            }
            
            continue;
            
        }
        
    }
    return dists[R][C];

}

int main() {
    cin >> T;
    while(T--) {
        cin >> R >> C;
        for (int i = 1; i <= R; ++i) for (int j = 1; j <= C; ++j) dists[i][j] = MAXN;
        for (int i = 1; i <= R; ++i) for (int j = 1; j <= C; ++j) cin >> graph[i][j];
        int ans = BFS();
        cout << ((ans == MAXN) ? -1 : ans) << "\n";     
    }
    
}
