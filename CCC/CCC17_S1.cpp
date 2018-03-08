// https://dmoj.ca/problem/ccc17s1

#include <iostream>
#include <vector>
using namespace std;

int N, tmp, total1, total2;
vector<int> swifts;
vector<int> sems;

vector<int> largest;

void get_input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        swifts.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        sems.push_back(tmp);
    }
}

int main() {
    get_input();
    
    for (int i = 0; i < N; i++) {
        total1 += swifts[i];
        total2 += sems[i];
        if (total1 == total2) largest.push_back(i+1);
        
    }
    if (largest.size() == 0) cout << 0;
    else cout << largest.back();
}
