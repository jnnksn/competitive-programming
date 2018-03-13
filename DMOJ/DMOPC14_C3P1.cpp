// https://dmoj.ca/problem/dmopc14c3p1

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int day_one, m, current;

int main() {
   cin >> day_one >> m >> current;
   int total = day_one;
   for (int i = 1; i < current+1; i++) {
       total *= m;
   }
    
    cout << total;
}
