// https://dmoj.ca/problem/ccc15s1
// 3/18/2018

#include <bits/stdc++.h>
#define loop(x,y,z) for(int x = y; x < z; ++x)
using namespace std;

int K, tmp;
vector<int> x;
int main() {
    cin >> K;
    loop(i, 0, K) {
        cin >> tmp;
        if (tmp == 0) x.pop_back();
        else x.push_back(tmp);
        
    }
    int total = 0;
    loop(i, 0, x.size()) total += x[i];
    cout << total;
    
}
