// https://dmoj.ca/problem/ccc11j3
// 03/19/2018

#include <bits/stdc++.h>
#define loop(x,y,z) for(int x = y; x < z; ++x)
#define all(x) x.begin(), x.end()
using namespace std;
vector<int> x;
int num1, num2, tmp;
int main() {
    cin >> num1 >> num2;
    x.push_back(num1);
    x.push_back(num2);
    while (true) {
        tmp = num1 - num2;
        x.push_back(tmp);
        num1 = num2;
        num2 = tmp;
        if (num1 < num2) break;
        
    }
    cout << x.size();
}
