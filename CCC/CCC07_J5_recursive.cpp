// https://dmoj.ca/problem/ccc07j5
// recursive approach
#include <iostream>
#include <vector>
using namespace std;

int minimum, maximum, N, tmp, num_ways = 0;
vector<int> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

int find_motels(int distances) {
    if (distances == 7000) return num_ways += 1;
    else {
        // loop through all available motels
        for (int i = 0; i < motels.size(); i++) {
            // if the motel subtract current distance is within min/max. Means you are able to reach!
            if (minimum <= motels[i] - distances && motels[i] - distances <= maximum) {
                find_motels(motels[i]);
            }
        }
    }
}

int main() {
    cin >> minimum >> maximum >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        motels.push_back(tmp);
    }
    
    find_motels(0);
    cout << num_ways;
}
