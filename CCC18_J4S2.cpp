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
