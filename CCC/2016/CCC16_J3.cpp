// https://dmoj.ca/problem/ccc16j3

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string word;
int C = 0;
vector<string> track;
void find_pal(string N) {
    
    if (N == string(N.rbegin(), N.rend())) {
        if (N.length() > C) C = N.length();
    } else {
        if(find(track.begin(), track.end(), N) != track.end()) {
        } else {
            track.push_back(N);
            find_pal(N.substr(1));
            find_pal(N.substr(0, N.length()-1));
        }
            
        
    }
}

int main() {
    cin >> word;
    find_pal(word);
    cout << C;
}
