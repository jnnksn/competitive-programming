// https://dmoj.ca/problem/dwite09c6p4
// 04/29/2018

#include <iostream>
#include <vector>
using namespace std;
// variables
int amount, n, visited[101], tmp;
vector<int> coins;
int TC = 5;
// functions
bool find(int N, int U) {
    if (U < visited[N]) visited[N] = U;
    else return true;
    
    if (N >= amount) return true;
    else {
        for (auto i : coins) find(N+i, U+1);
    }
    return true;
}


int main() {
    while(TC--) {
        cin >> amount >> n;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            coins.push_back(tmp);
        }
        for (int j = 0; j < 102; ++j) visited[j] = 9999;
        
        find(0,0);
        
        cout << visited[amount] << "\n";
        coins.clear();
    }
}
