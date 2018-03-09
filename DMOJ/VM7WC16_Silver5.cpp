#include <iostream>
using namespace std;

int N, comb[3];

void get_input() {
    cin >> N;
    cin >> comb[0];
    cin >> comb[1];
    cin >> comb[2];
}


int main() {
    get_input();
    int states[N+1];
    for (int x = 0; x < N+1; ++x) states[x] = 0;
   
    for (int i = 1; i < N+1; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (comb[j] <= i && (states[i-comb[j]]+1) > states[i]) {
                states[i] = states[i-comb[j]]+1;
              
            }
        }
    }
    
    cout << states[N];
    
}

