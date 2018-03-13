// https://dmoj.ca/problem/dmopc14c2p2

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int log_length;
string loga, tmp = "";
vector<string> splits;

int main() {
    cin >> log_length >> loga;
  
    for (int i = 0; i < loga.length(); i++) {
        if (loga[i] == 'O') tmp += "O";
        else {
            if (tmp.size() != 0) splits.push_back(tmp);
            tmp = "";
        }
    }
    
    if (tmp.size() != 0) splits.push_back(tmp);
    
    
    cout << splits.size() << "\n";
    //if (vector.size() == 0)
    for (int i = 0; i < splits.size(); i++) {
        for (int x = 0; x < splits[i].length(); x++) {
            cout << splits[i][x];
        }
        cout << "\n";
    }
    
}
