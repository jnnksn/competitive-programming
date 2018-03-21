// https://dmoj.ca/problem/ccc10j5
// 03/20/2018

#include <bits/stdc++.h>
#define REP(x,y,z) for(int x = y; x < z; ++x)
#define ALL(x) x.begin(), x.end()
#define INF (int)1e9
#define EACH(x, y) for (auto x : y)
#define IN(x,y) find(ALL(x), y)
using namespace std;
int x,y,xz,yz;
int visited[9][9];
int move(int xe, int ye, int num_moves){
    if (xe <= 8 && xe > 0 && ye > 0 && ye <= 8 && num_moves < visited[xe][ye]) {
        
        visited[xe][ye] = num_moves;
        int k = num_moves + 1;
        move(xe + 1, ye + 2, k);
        move(xe - 1, ye + 2, k);
        move(xe + 1, ye - 2, k);
        move(xe - 1, ye - 2, k);
        move(xe + 2, ye - 1, k);
        move(xe + 2, ye + 1, k);
        move(xe - 2, ye + 1, k);
        move(xe - 2, ye - 1, k);
        
    }

}
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> x >> y >> xz >> yz;
  REP(i, 1, 9) REP(j, 1, 9) visited[i][j] = INF;

  move(x,y,0);
  
  cout << visited[xz][yz];
 
}
