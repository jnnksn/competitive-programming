// https://dmoj.ca/problem/ccc18j2

#include <iostream>
#include <string>
using namespace std;
int N, num_occupied = 0;
string dayOne, dayTwo;
int main() {
    cin >> N >> dayOne >> dayTwo;
    
    for (int i = 0; i < N; i++) {
        if (dayOne[i] == 'C' && dayTwo[i] == 'C') num_occupied++;
    }
    
    cout << num_occupied;
}
