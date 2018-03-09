// https://dmoj.ca/problem/rgss1

#include <iostream>
using namespace std;

int cap, comb[2];

void get_input() {
    cin >> comb[0];
    cin >> comb[1];
    cin >> cap;
}


int main() {
    get_input();
    int num_cap[cap+1];
 
    for (int i = 0; i < cap+1; ++i) num_cap[i] = 99999;
    num_cap[0] = 0;
    
    for (int i = 1; i < cap+1; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (comb[j] <= i && num_cap[i-comb[j]]+1 < num_cap[i]) {
                if (num_cap[i-comb[j]]+1 != 0) num_cap[i] = num_cap[i-comb[j]] + 1;
            }
        }
    }
    
    int largest = 0;
    for (int i = 0; i < cap+1; ++i) {
        if (i >= largest && num_cap[i] != 99999) largest = i;
    }
    
    cout << largest;
}
