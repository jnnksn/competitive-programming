#include <iostream>
#include <math.h>
using namespace std;
int total, numKids, totalStudents[4], price[4] = {12, 10, 7, 5}, totalMoney=0;
float percentStudents[4];


void get_input() {
  cin >> total;
  for (int i = 0; i < 4; i++) cin >> percentStudents[i];
  cin >> numKids;
}

int main() {
  for (int x = 0; x < 10; x++) {
    get_input();
    for (int i = 0; i < 4; i++) {
      totalStudents[i] = floor(percentStudents[i] * numKids);
      totalMoney += totalStudents[i] * price[i];
    } 
    
    
    
    if ((totalMoney * 0.5) < total) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    
    totalMoney = 0;
  }
  
  return 0;
}
