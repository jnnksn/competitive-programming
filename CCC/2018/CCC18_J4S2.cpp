// https://dmoj.ca/problem/ccc18s2
// -------------------------------
// Most solutions go with a mathematical approach, however I solved it differently.
// We notice that the indexes in the 2d table change in a pattern when we rotate.
// 1 2 3
// 4 5 6
// 7 8 9
//
// when rotated once:
//
// 3 6 9
// 2 5 8
// 1 4 7
//
// Notice how the first row becomes the first column
// the second row becomes the second column
// and the third row becomes the third column
//
// Thus, knowing this we can simply check if the table is correct based on the criteria given, and if not
// we rotate and check again.
// this continues until we eventually find the correct table (max 4 times since 90 + 90 + 90 + 90 = 360, and we repeat after that)
// -------------------------------
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n, mainTable[101][101], tmp[101][101];
int use;

// rotation function
void rotate() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      tmp[i][j] = mainTable[j][use];
    }
    use -= 1;
  }
  use = n-1;
  for (int i = 0; i < n; i++) for(int j = 0; j < n; j++) mainTable[i][j] = tmp[i][j];
}

// check function
bool check() {
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (mainTable[i][j] < mainTable[i][j-1]) return false;
      if (mainTable[i][j] < mainTable[i-1][j]) return false;
    }
  }
  return true;
}


int main() {
  cin >> n;
  use = n-1;
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> mainTable[i][j];
      tmp[i][j] = mainTable[i][j];
    }
  } 
  
  for (int i = 0; i < 3; i++) {
     if (check() == false) {
       rotate();
     } else {
       break;
     }
  } 
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << mainTable[i][j] << " ";
    }
    cout << "\n";
  }
  
}
