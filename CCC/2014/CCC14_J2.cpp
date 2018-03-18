// https://dmoj.ca/problem/ccc14j2

#include <iostream>
#include <string>
#define loop(x,y,z) for(int x = y; x < z; ++x)

using namespace std;

int num_votes, totals = 0;
string votes;

int main() {
   cin >> num_votes;
   cin >> votes;
   loop(i,0,votes.length()) {
       if (votes[i] == 'A') totals += 1;
       if (votes[i] == 'B') totals -= 1;
   }
   
   if (totals > 0) cout << "A\n";
   else if(totals < 0) cout << "B\n";
   else cout << "Tie\n";
    
}
