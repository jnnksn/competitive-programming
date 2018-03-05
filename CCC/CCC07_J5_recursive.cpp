// https://dmoj.ca/problem/ccc07j5
// recursive approach
#include <iostream>
#include <vector>
using namespace std;

int minimum, maximum, N, tmp, num_ways = 0;
vector<int> motels;

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
    motels.push_back(0);
    motels.push_back(990);
    motels.push_back(1010);
    motels.push_back(1970);
    motels.push_back(2030);
    motels.push_back(2940);
    motels.push_back(3060);
    motels.push_back(3930);
    motels.push_back(4060);
    motels.push_back(4970);
    motels.push_back(5030);
    motels.push_back(5990);
    motels.push_back(6010);
    motels.push_back(7000);
    
    cin >> minimum >> maximum >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        motels.push_back(tmp);
    }
    
    find_motels(0);
    cout << num_ways;
}
