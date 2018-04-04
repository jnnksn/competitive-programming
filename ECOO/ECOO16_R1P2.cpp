// https://dmoj.ca/problem/ecoo16r1p2

#include <iostream>
#include <vector>
using namespace std;

int N, targets[5];
vector<int> diff_factors;
bool types[101];


void get_input() {
    cin >> N;
    int k;
    for (int i = 0; i < N; i++) {
        cin >> k;
        types[k] = true;
    }
    for (int i = 1; i < 101; i++) {
        if (types[i]) diff_factors.push_back(i);
    }
    
    for (int x = 0; x < 5; x++) cin >> targets[x];
}

bool if_reach(int K, int turns) {
    if (turns == 0) {
        return K == 0;
    } 
    
    for (int x = 0; x < diff_factors.size(); x++) {
        if (if_reach(K - diff_factors[x], turns-1)) return true;
        if (K % diff_factors[x] == 0 && if_reach(K / diff_factors[x], turns-1)) return true;
    }
    return false;
    
    
}

int main() {
    for (int _ = 0; _ < 10; _++) {
        diff_factors.clear(); fill(types, types + 101, false);
        get_input();
    
        for (int j = 0; j < 5; j++) {
             cout << ((if_reach(targets[j], 3)) ? 'T' : 'F');
        }
        cout << "\n";
    }
    
}
