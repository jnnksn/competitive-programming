// https://dmoj.ca/problem/ccc15s1
// 3/18/2018
// Lowered required time by removing additional loop: O(n) time.

#include <bits/stdc++.h>
#define loop(x,y,z) for(int x = y; x < z; ++x)
using namespace std;

int K, tmp, total = 0;
vector<int> x;
int main() {
    cin >> K;
    loop(i, 0, K) {
        cin >> tmp;
        if (tmp == 0) {
            total -= x[x.size()-1];
            x.pop_back();
        }
        else {
            x.push_back(tmp);
            total += tmp;
        }        
    }
    cout << total;
  
}
