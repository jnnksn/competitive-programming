// https://dmoj.ca/problem/set
// 3/18/2018

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define loop(x,y,z) for(int x = y; x < z; ++x)
#define all(x) x.begin(), x.end()

int N, tmp;
vector<int> k;
int main() {
    cin >> N;
    loop(i, 0, N) {
        cin >> tmp;
        if (find(all(k), tmp) == k.end()) {
            k.push_back(tmp);
        }
    }
   
   cout << k.size();
}
