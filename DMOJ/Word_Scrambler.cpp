// https://dmoj.ca/problem/ics4p1
// Recursive Approach

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string word;
vector<char> letters;
vector<string> found;
void combos(string N) {
    if (N.length() == word.length()) {
        if(find(found.begin(), found.end(), N) != found.end()) {
        }
        else found.push_back(N);
    }
    else {
        for (int i = 0; i < letters.size(); ++i) {
            if (N.find(letters[i]) != string::npos) continue;
            else {
                string C = N + letters[i];
                combos(C);
            }
        }
    }
}

int main() {
   
    cin >> word;
    for (auto i : word) {
        letters.push_back(i);
    }
    combos("");
    sort(found.begin(), found.end());
    for (auto i : found) cout << i << "\n";
    letters.clear();
    found.clear();
    
}
