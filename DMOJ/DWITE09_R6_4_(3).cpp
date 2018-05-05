// https://dmoj.ca/problem/dwite09c6p4
// 05/05/2018
// Iterative Approach.

#include <iostream>
#include <vector>
using namespace std;

int visited[101], amount, n, tmp, TC = 5;
vector<int> coins;
int main() {
    while (TC--) {
        cin >> amount >> n;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            coins.push_back(tmp);
        }
        
        for (int i = 0; i < 101; ++i) {
            visited[i] = 9999;
        }
        
        visited[0] = 0;
        
        for (int i = 0; i < 101; ++i) {
            for (auto j : coins) {
                if (i+j < 101) {
                    if (visited[i] + 1 < visited[i + j]) {
                        visited[i + j] = visited[i] + 1;
                    }
                }
            }
        }
        cout << visited[amount] << "\n";
        coins.clear();
    }
}


