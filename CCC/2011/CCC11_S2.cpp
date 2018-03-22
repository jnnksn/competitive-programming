// https://dmoj.ca/problem/ccc11s2
// 03/22/2018

#include <bits/stdc++.h>
#define REP(x,y,z) for(int x = y; x < z; ++x)
#define ALL(x) x.begin(), x.end()
#define INF (int)1e9
#define EACH(x, y) for (auto x : y)
#define IN(x,y) find(ALL(x), y)
using namespace std;

vector<string> g1;
vector<string> g2;
string tmp;
int N, total = 0;

int main() {
    cin >> N;
   
    REP(i, 0, N) {
        cin >> tmp;
        g1.push_back(tmp);
       
    }
    REP(i, 0, N) {
        cin >> tmp;
        g2.push_back(tmp);
      
    }
    
    REP(i, 0, N) {
        if (g1[i] == g2[i]) total += 1;
    }
    cout << total << "\n";
    
}
