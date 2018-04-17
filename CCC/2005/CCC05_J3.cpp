// https://dmoj.ca/problem/ccc05j3

#include <bits/stdc++.h>

using namespace std;
string x;
vector<string> moves;
vector<string> places;
int main() {
    while (true) {
        cin >> x;
        if (x == "R" || x == "L") moves.push_back(x);
        else places.push_back(x);
        if (x == "SCHOOL") break;
    }
 
    for (int i = moves.size()-1; i > -1; --i) {

        if (i == 0 && moves[i] == "R") {
            cout << "Turn " << "LEFT" << " into your HOME.\n"; 
            break;
        }
        if (i == 0 && moves[i] == "L") {
            cout << "Turn " << "RIGHT" << " into your HOME.\n"; 
            break;
        }
        if (moves[i] == "R") {
            cout << "Turn " << "LEFT " << "onto " << places[i-1] << " street.\n";
        }
        if (moves[i] == "L") {
            cout << "Turn " << "RIGHT " << "onto " << places[i-1] << " street.\n";
        }
    }

}
