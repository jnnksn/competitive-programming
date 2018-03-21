// https://dmoj.ca/problem/bf3
// 03/21/2018

#include <bits/stdc++.h>
#define REP(x,y,z) for(int x = y; x <= z; ++x)
#define ALL(x) x.begin(), x.end()
#define INF (int)1e9
#define EACH(x, y) for (auto x : y)
#define IN(x,y) find(ALL(x), y)
using namespace std;

long lower_limit;
bool is_prime = true;
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> lower_limit;
  while(true) {
      REP(i, 2, pow(lower_limit, 0.5)) {
          if (lower_limit % i == 0) {is_prime = false; break;}
            
      }
      if (lower_limit == 1) is_prime = false;
      if (is_prime) {cout << lower_limit; break;}
      else {lower_limit += 1; is_prime = true;}
  }
 
}
