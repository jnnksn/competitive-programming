// https://dmoj.ca/problem/dwite10c2p3

// recursive solution
// got main idea within 10 minutes.
// poor understanding of c++ made it take me 2 hours. 

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int increase;
string grid[8], tmp;
vector<int> totals;

bool find_path(int x, int y, int total) {
    
    if (y == 0 && x == 7) {
        totals.push_back(total);
        return true;
    }
    else if (x <= 7 && y >= 0 && grid[y][x] != '#') {
        
        if (grid[y][x] == '.') increase = 0;
        else increase = grid[y][x] - '0';
       
        int totalz = total + increase;
        return find_path(x+1,y, totalz), find_path(x,y-1, totalz);
    }
    return false;
    
}

int main() {

    
    for (int i = 0; i < 5; i++) {
        for (int i = 0; i < 8; i++) cin >> grid[i];
        cin >> tmp;
        find_path(0, 7,0);
        sort(totals.begin(), totals.end());
        cout << totals[totals.size()-1] << "\n";
   
        totals.clear();
        
       
    }   
}
