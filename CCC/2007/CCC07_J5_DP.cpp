// https://dmoj.ca/problem/ccc07j5
// Dynamic Programming approach
// 40/50

#include <iostream>
#include <vector>
using namespace std;

vector<int> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

int minimum, maximum, N, tmp;

int main() {
    cin >> minimum >> maximum >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        motels.push_back(tmp);
    }
    
    int tmpk;
    int num_ways[motels.size()];
    for (int i = 0; i < motels.size(); i++) num_ways[i] = 0;
    num_ways[0] = 1;
    for (int i = 0; i < motels.size(); i++) {
        for (int x = i+1; x < motels.size(); x++) {
            tmpk = motels[x] - motels[i];
            if (minimum <= tmpk && tmpk <= maximum) {
                if (num_ways[i] != 0) num_ways[x] += num_ways[i];
            } 
        }
    }
    
    cout << num_ways[motels.size()-1];
